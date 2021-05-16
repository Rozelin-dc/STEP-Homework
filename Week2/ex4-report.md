## 概要

[ex4.cpp](./ex4.cpp)の`handleCache`は、[ex3-report.md](./ex3-report.md)の改善後の手順をそのままプログラムにしたものである。`history`と`caches`も[ex3-report.md](./ex3-report.md)で定義したものとほぼ同じだが、ハッシュテーブルに値を複数持たせるために、`_siteData`というWebページ(`web`)と`history`中のURLの出現回数(`count`)を値として持つ構造体を定義し、`caches`の値はキーとなっているURLと対応する`siteData_t`(`_siteData`の型名)とした。また、実装の都合上、今回はWebページのデータはURLと同じ文字列とした。

`doHistoryOrganizing`では、`history`の末尾のURL`historyEndUrl`の`caches`中の`count`を参照し、2以上なら`historyEndUrl`の`caches`中の`count`を-1し、`history`の末尾を削除するという作業を、`historyEndUrl`の`caches`中の`count`が2未満になるまで繰り返している。この作業を、新しいサイトを訪問するたびに行うことで、`history`のサイズが大きくなり過ぎないようにしている。

また、プログラム冒頭の`MAX_CACHE_SIZE`で、保存できるキャッシュの最大数を定義しており、新しく訪れたURLが`caches`に含まれていないかつ`caches`のサイズが`MAX_CACHE_SIZE`より小さい時は、`caches`へのページデータの追加と`history`の先頭へのURL追加のみを行っている。

## 実行方法

最初に、疑似的に訪れたとみなすURLの数`n`を入力し、その後URLを訪れた順に入力する。1つURLを訪れて`handleCache`が実行された後、`history`の順に`caches`の中身が出力されるので、そこでキャッシュが正常に動作しているか確認できる。

