# WebDNNによるChainerモデル->ブラウザ用形式への変換
# pip install webdnn および、emscriptenのセットアップが必要
# http://kripken.github.io/emscripten-site/docs/getting_started/downloads.html
# em++コマンドが動作する状態で以下を実行。
# python3 model_convert.py

import numpy as np
import chainer
from webdnn.backend import generate_descriptor
from webdnn.frontend.chainer import ChainerConverter
from model import Model


def get_graph(model):
    dummy_input = np.zeros((1, 86, 9, 9), dtype=np.float32)
    x = chainer.Variable(dummy_input)
    with chainer.using_config("train", False):  # disable batch normalization
        move, value = model.forward(x)
    graph = ChainerConverter().convert([x], [move, value])
    return graph


def load_model():
    model = Model()
    chainer.serializers.load_npz("weight/model_20180401095426_iter_340000", model)
    return model


def main():
    model = load_model()
    graph = get_graph(model)
    exec_info = generate_descriptor("webassembly", graph, constant_encoder_name="eightbit")
    exec_info.save("../public/webdnn_model")


main()
