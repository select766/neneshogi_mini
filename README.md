# ねね将棋mini
Webブラウザ上で動作する、Deep Learningによる将棋方策モデルのデモです。現局面から探索なしに最善と思われる手を指します。

# 開発用セットアップ

```
git submodule init
git submodule update
```

## DNNモデルの変換を行う場合
- python3.6以降のインストール (Anaconda等)
- 依存pythonパッケージのインストール (requirements.txt)
- [emscriptenのセットアップ](http://kripken.github.io/emscripten-site/docs/getting_started/downloads.html)

webdnn等のパッケージインストール
```
pip install -r requirements.txt
```

シェルを立ち上げるごとに、emscriptenをインストールしたディレクトリで
```
source ./emsdk_env.sh
```
の実行が必要なことに注意。

# DNNモデルの変換
```
cd model_convert
python3 model_convert.py
```

出力先: `public/webdnn_model`

