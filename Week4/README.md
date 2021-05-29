## 使用言語

C++(g++ 8.1.0)

## 概要

- [main.cpp](./main.cpp)：必須宿題、”Google”から”渋谷”までの最短経路を探して出力するコード
- [utils.cpp](./utils.cpp)：ウィキペディアのデータを読み込むための関数が定義されているコード
- [utils.h](./utils.h)：[utils.cpp](./utils.cpp)のヘッダファイル。Week4全体で利用する構造体の定義もされている

## 実行方法

### 準備

g++を使えるようにする。

[wikipedia_data.zip](https://drive.google.com/file/d/1zqtjSb-ZoR4rzVUWZrjNSES5GKJhYmmH/view?usp=sharing) をダウンロードして解凍し、以下のようなディレクトリ構成にする。

```
Week4
├── wikipedia_data
│   ├── graph_small.png
│   ├── links_small.txt
│   ├── links.txt
│   ├── pages_small.txt
│   └── pages.txt
├── README.md
├── main.cpp
├── utils.cpp
└── utils.h
```

ターミナル上で日本語を正常に出力するためには、`pages.txt`と`main.cpp`は`Shift JIS`でエンコードされている必要がある。

### 実行

ターミナルで以下のコマンドを実行後、`a.exe`を実行する。

```
g++ main.cpp utils.cpp
```

”Google”から”渋谷”までの最短経路が表示される。

[main.cpp の10行目](https://github.com/Rozelin-dc/STEP-Homework/blob/week4/Week4/main.cpp#L10)の`”Google”`、`”渋谷”`を変更すれば、他のページ間の最短経路も検索可能。

