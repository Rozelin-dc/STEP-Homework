#include <bits/stdc++.h>
using namespace std;

#define MAX_CACHE_SIZE 3 // 保存できるキャッシュの最大数

/** キャッシュのクラス */
class Cache
{
  private:
    deque<string> history; // 先頭に行くほど最近に訪れたURLが保存されている配列
    unordered_map<string, pair<string, int>> caches; // URLをキー first: Webページ, second: history 中の出現回数 の pair を値に持つハッシュテーブル
    void removeUnnecessaryHistory();
  public:
    void handleCache(string currentUrl);
    deque<string> getHistory();
    unordered_map<string, pair<string, int>> getCaches();
};
