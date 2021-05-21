#include <bits/stdc++.h>
using namespace std;

#define MAX_CACHE_SIZE 3 // 保存できるキャッシュの最大数


class Cache
{
  deque<string> history; // 先頭に行くほど最近に訪れたURLが保存されている配列
  unordered_map<string, pair<string, int>> caches; // URLをキー first: Webページ, second: history 中の出現回数 の pair を値に持つハッシュテーブル
  void doHistoryOrganizing();
  public:
    void handleCache(string currentUrl);
    deque<string> getHistory();
    unordered_map<string, pair<string, int>> getCaches();
};

void test();

int main() {
  test();
  int n;
  cin>>n;

  Cache cache;

  string currentUrl; // 新しく訪れたURL

  for (int i = 0; i < n; i++) {
    cin>>currentUrl;
    cache.handleCache(currentUrl);
  }
}

void Cache::handleCache(string currentUrl) {
  // currentUrl が caches に含まれるか検索
  auto itr = caches.find(currentUrl);
  if (itr != caches.end()) { // currentUrl が caches に含まれていた場合
    if(history[0] == currentUrl) {
      doHistoryOrganizing();
      return;
    }

    history.push_front(currentUrl);
    caches.at(currentUrl).second += 1;

    doHistoryOrganizing();
    return;
  } else { // currentUrl が caches に含まれていない場合
    if(caches.size() < MAX_CACHE_SIZE) { // 保存できるキャッシュにまだ余裕がある時
      history.push_front(currentUrl);
      caches[currentUrl] = make_pair(currentUrl, 1);
      return;
    }

    doHistoryOrganizing();
    string historyEndUrl = history[history.size()- 1]; // history の末尾のURL
    caches.erase(historyEndUrl); // キャッシュ消去
    history.pop_back(); // history の末尾削除

    // 新しく訪れたURLを history と caches に追加
    history.push_front(currentUrl);
    caches[currentUrl] = make_pair(currentUrl, 1);
    return;
  }
}

/** history の整理をする */
void Cache::doHistoryOrganizing() {
  string historyEndUrl = history[history.size()- 1]; // history の末尾のURL
  while (caches.at(historyEndUrl).second >= 2)
  {
    caches.at(historyEndUrl).second -= 1;
    history.pop_back();
    historyEndUrl = history[history.size() - 1];
  }
  return;
}

deque<string> Cache::getHistory() {
  return history;
}

unordered_map<string, pair<string, int>> Cache::getCaches() {
  return caches;
}

void test() {
  Cache cache;

  unordered_map<string, pair<string, int>> expectedCaches = {};

  if(cache.getHistory() != (deque<string>){}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("a");
  expectedCaches = {{"a", make_pair("a", 1)}};
  if(cache.getHistory() != (deque<string>){"a"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("b");
  expectedCaches = {
    {"a", make_pair("a", 1)},
    {"b", make_pair("b", 1)}
  };
  if(cache.getHistory() != (deque<string>){"b", "a"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("b");
  expectedCaches = {
    {"a", make_pair("a", 1)},
    {"b", make_pair("b", 1)}
  };
  if(cache.getHistory() != (deque<string>){"b", "a"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("c");
  expectedCaches = {
    {"a", make_pair("a", 1)},
    {"b", make_pair("b", 1)},
    {"c", make_pair("c", 1)}
  };
  if(cache.getHistory() != (deque<string>){"c", "b", "a"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("d");
  expectedCaches = {
    {"d", make_pair("d", 1)},
    {"b", make_pair("b", 1)},
    {"c", make_pair("c", 1)}
  };
  if(cache.getHistory() != (deque<string>){"d", "c", "b"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("c");
  expectedCaches = {
    {"d", make_pair("d", 1)},
    {"b", make_pair("b", 1)},
    {"c", make_pair("c", 2)}
  };
  if(cache.getHistory() != (deque<string>){"c", "d", "c", "b"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("d");
  expectedCaches = {
    {"d", make_pair("d", 2)},
    {"b", make_pair("b", 1)},
    {"c", make_pair("c", 2)}
  };
  if(cache.getHistory() != (deque<string>){"d", "c", "d", "c", "b"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("a");
  expectedCaches = {
    {"d", make_pair("d", 2)},
    {"a", make_pair("a", 1)},
    {"c", make_pair("c", 2)}
  };
  if(cache.getHistory() != (deque<string>){"a", "d", "c", "d", "c"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("a");
  expectedCaches = {
    {"d", make_pair("d", 1)},
    {"a", make_pair("a", 1)},
    {"c", make_pair("c", 1)}
  };
  if(cache.getHistory() != (deque<string>){"a", "d", "c"}) return;
  if(cache.getCaches() != expectedCaches) return;

  std::cout<<"OK"<<endl;
  return;
}
