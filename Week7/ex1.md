## 概要

$1024 \times 1024$ の行列積について、6種類のループ順序全てにおいて各3回実行時間を計測し、その平均を[result-vector.csv](./result-vector.csv)に記録した。

## 考察

forループの順番を変えたところ、実行時間にある程度の変化は見られたが、授業内で見せていただいたほどの劇的な変化は見られなかった。C++のvectorでは、連続した添え字のアドレスが連番にはなっていないと聞いたことがあるので、それが原因ではないかと思っている。

結果として、全ての行列を横向きに見ていくi-k-jループではなく、行列を1つ縦向きに見ていくことになるk-i-jループが最も実行時間が短かった。予想ではi-k-jループが最も早いと考えていたが、そうはならなかったのは、前述の理由によるものと考えられる。
