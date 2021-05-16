## 概要

[ex1.cpp](./ex1.cpp) では、行列のサイズ`n`を入力として受け取り、`makeMatrix`でn×n行列をランダムに生成。その後`multMatrixes`で生成した2つの行列の掛け算を行っている。[ex1-result.csv](./ex1-result.csv) には、`multMatrixes`にかかる時間を計測し、結果を出力している。`Time` の単位は `sec` である。

`makeMatrix`で生成される行列の各成分は整数値で、その上限と下限はそれぞれプログラム冒頭の`MIN_MATRIX_COMPONENT`, `MAX_MATRIX_COMPONENT`で定義されている。

## 考察

`multMatrixes` では、行列計算の定義通りに計算を行い、`N` 回回す for文が三重になっているので、この部分の時間計算量は$O(N^3)$である。R言語（[ex1-plot.R](./ex1-plot.R)）を利用して結果をグラフにしたものが [ex1-graph.png](./ex1-graph.png) である。グラフ中の点は、実際の計測結果で、青い線は$y=x^3$のグラフである。このグラフから、実行時間は$N^3$に比例していることがわかる。

