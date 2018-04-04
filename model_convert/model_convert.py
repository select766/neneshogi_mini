# WebDNNによるChainerモデル->ブラウザ用形式への変換
# pip install webdnn および、emscriptenのセットアップが必要
# http://kripken.github.io/emscripten-site/docs/getting_started/downloads.html
# em++コマンドが動作する状態で以下を実行。
# python3 model_convert.py

import os
import json
import numpy as np
import chainer
from webdnn.backend import generate_descriptor
from webdnn.frontend.chainer import ChainerConverter
from model import Model

model_configs = [
    {"path": "weight/model_20180401095426_iter_340000",
     "name": "small1", "options": {"ch": 64, "depth": 4}},
    {"path": "weight/model_20180316103614_iter_1953125",
     "name": "large1", "options": {"ch": 192, "depth": 4}}
]


def get_graph(model):
    dummy_input = np.zeros((1, 86, 9, 9), dtype=np.float32)
    x = chainer.Variable(dummy_input)
    with chainer.using_config("train", False):  # disable batch normalization
        move, value = model.forward(x)
    graph = ChainerConverter().convert([x], [move, value])
    return graph


def load_model(model_config):
    model = Model(**model_config["options"])
    chainer.serializers.load_npz(model_config["path"], model)
    return model


def export_model_metadata(model_descriptions, dst):
    ts = f"""
export let models = {json.dumps(model_descriptions)};
    """
    with open(dst, "w") as f:
        f.write(ts)


def main():
    model_descriptions = []
    for model_config in model_configs:
        model = load_model(model_config)
        graph = get_graph(model)
        exec_info = generate_descriptor("webassembly", graph, constant_encoder_name="eightbit")
        output_dir = f"../docs/webdnn_model/{model_config['name']}"
        exec_info.save(output_dir)
        data_size = os.path.getsize(f"{output_dir}/weight_webassembly.bin") + 65536  # 重み以外の関連ファイルサイズ加算

        model_descriptions.append({"name": model_config["name"],
                                   "description": f"{model_config['name']} {data_size // 1024}kB"})
    export_model_metadata(model_descriptions, "../src/models.ts")


main()
