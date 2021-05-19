#include <bits/stdc++.h>
using namespace std;

#define MAX_CACHE_SIZE 3 // 保存できるキャッシュの最大数

/** Webページと history 中のURLの出現回数を値として持つ構造体 */
struct _siteData
{
  string web;
  int count;
};
typedef struct _siteData siteData_t;

class Cache
{
  deque<string> history; // 先頭に行くほど最近に訪れたURLが保存されている配列
  unordered_map<string, siteData_t> caches; // URLをキー、siteData を値に持つハッシュテーブル
  void doHistoryOrganizing();
  public:
    void handleCache(string currentUrl);
    deque<string> getHistory();
    unordered_map<string, siteData_t> getCaches();
};

void test();

int main() {
  test();
  /* int n;
  cin>>n;

  Cache cache;

  string currentUrl; // 新しく訪れたURL

  for (int i = 0; i < n; i++) {
    cin>>currentUrl;
    cache.handleCache(currentUrl);
  } */
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
    caches.at(currentUrl).count += 1;

    doHistoryOrganizing();
    return;
  } else { // currentUrl が caches に含まれていない場合
    if(caches.size() < MAX_CACHE_SIZE) { // 保存できるキャッシュにまだ余裕がある時
      history.push_front(currentUrl);
      caches[currentUrl] = (siteData_t){ currentUrl, 1 };
      return;
    }

    doHistoryOrganizing();
    string historyEndUrl = history[history.size()- 1]; // history の末尾のURL
    caches.erase(historyEndUrl); // キャッシュ消去
    history.pop_back(); // history の末尾削除

    // 新しく訪れたURLを history と caches に追加
    history.push_front(currentUrl);
    caches[currentUrl] = (siteData_t){ currentUrl, 1 };
    return;
  }
}

/** history の整理をする */
void Cache::doHistoryOrganizing() {
  string historyEndUrl = history[history.size()- 1]; // history の末尾のURL
  while (caches.at(historyEndUrl).count >= 2)
  {
    caches.at(historyEndUrl).count -= 1;
    history.pop_back();
    historyEndUrl = history[history.size() - 1];
  }
  return;
}

deque<string> Cache::getHistory() {
  return history;
}

unordered_map<string, siteData_t> Cache::getCaches() {
  return caches;
}

void test() {
  Cache cache;

  unordered_map<string, siteData_t> expectedCaches = {};

  if(cache.getHistory() != (deque<string>){}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("a");
  expectedCaches = {{"a", (siteData_t){"a", 1}}};
  if(cache.getHistory() != (deque<string>){"a"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("b");
  expectedCaches = {
    {"a", (siteData_t){"a", 1}},
    {"b", (siteData_t){"b", 1}}
  };
  if(cache.getHistory() != (deque<string>){"b", "a"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("b");
  expectedCaches = {
    {"a", (siteData_t){"a", 1}},
    {"b", (siteData_t){"b", 1}}
  };
  if(cache.getHistory() != (deque<string>){"b", "a"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("c");
  expectedCaches = {
    {"a", (siteData_t){"a", 1}},
    {"b", (siteData_t){"b", 1}},
    {"c", (siteData_t){"c", 1}}
  };
  if(cache.getHistory() != (deque<string>){"c", "b", "a"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("d");
  expectedCaches = {
    {"d", (siteData_t){"d", 1}},
    {"b", (siteData_t){"b", 1}},
    {"c", (siteData_t){"c", 1}}
  };
  if(cache.getHistory() != (deque<string>){"d", "c", "b"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("c");
  expectedCaches = {
    {"d", (siteData_t){"d", 1}},
    {"b", (siteData_t){"b", 1}},
    {"c", (siteData_t){"c", 2}}
  };
  if(cache.getHistory() != (deque<string>){"c", "d", "c", "b"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("d");
  expectedCaches = {
    {"d", (siteData_t){"d", 2}},
    {"b", (siteData_t){"b", 1}},
    {"c", (siteData_t){"c", 2}}
  };
  if(cache.getHistory() != (deque<string>){"d", "c", "d", "c", "b"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("a");
  expectedCaches = {
    {"d", (siteData_t){"d", 2}},
    {"a", (siteData_t){"b", 1}},
    {"c", (siteData_t){"c", 2}}
  };
  if(cache.getHistory() != (deque<string>){"a", "d", "c", "d", "c"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("a");
  expectedCaches = {
    {"d", (siteData_t){"d", 1}},
    {"a", (siteData_t){"b", 1}},
    {"c", (siteData_t){"c", 1}}
  };
  if(cache.getHistory() != (deque<string>){"a", "d", "c"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cout<<"OK"<<endl;
  return;
}
