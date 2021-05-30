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

[main.cpp の11行目](https://github.com/Rozelin-dc/STEP-Homework/blob/week4/Week4/main.cpp#L11)の`”Google”`、`”渋谷”`を変更すれば、他のページ間の最短経路も検索可能。

## プログラムの説明

今回は最短経路を見つけたいので、探索方法には幅優先探索を採用した。

`readData`はウィキペディアのデータを読み込む関数、`findSortestPath`は第二引数から第三引数までの最短経路を幅優先探索で探し、そこまでに通過するページが順に保存されている配列を返す関数、`findTargetId`は第二引数の名前のページのidを返す関数である。

`main`関数では、まず、ページのidをキー、名前とリンク付けられたページのidを値として持つハッシュテーブル`links`を用意し、`readData`関数に参照渡しすることでデータを読み込む。次に`foundPath`に`findSortestPath`の結果を保存し、もし空の配列が返ってきていたらパスが見つからなかったことになるので"Not Found"を出力し終了し、そうでなければ、見つかったパスを出力して終了する。

`findSortestPath`関数では、第二引数(スタート地点のページの名前。以後`start`と表記する)と第三引数(ゴールとなるページの名前。以後`end`と表記する)の値が等しくなければ、キューに`start`のページのidのみが保存されている状態で幅優先探索を開始する。また、探索終了時に、パスが見つかって探索が終了したのかそうでないのかを判断するためのフラグとして、変数`found`を用意した。
探索中は、まず、キューの先頭のページの名前が`end`と等しいかどうかを調べ、等しいなら`found`を`true`にして探索を終了し、等しくないなら、キューの先頭のページからリンク付けられているページをキューの末尾に追加する。このとき、探索中に訪れたページが保存されているハッシュテーブル`visitedPages`にすでに含まれているページはキューに追加せず、逆に含まれていないページは`visitedPages`にも、どのページから訪れたかという情報(この場合、キューの先頭のページ)とセットで保存する。`visitedPages`にどのページから訪れたかも保存するのは、探索が終わった後に、どのような経路をたどったのか簡単に再現できるようにするためである。
探索終了後は、`found`が`true`になっていなかったら、パスが見つからなかったということなので、空の配列を返して終了する。そうでなければ、探索中にたどった`start`から`end`までの経路を`visitedPages`を利用して逆向きにたどり、戻り値とする配列`foundPath`の先頭にどんどん追加していくことで最短経路を導き出す。

`findTargetId`関数では、`links`内を全探索し、名前が`targetName`と一致するページが見つかればそのページのidを返して終了し、見つからなければ"Not Found"を返して終了する。

