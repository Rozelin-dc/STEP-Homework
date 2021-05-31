#include <bits/stdc++.h>
#include "ex4-cach.h"
using namespace std;

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

  cache.handleCache("a");
  expectedCaches = {
    {"a", make_pair("a", 1)},
    {"b", make_pair("b", 1)},
    {"c", make_pair("c", 1)}
  };
  if(cache.getHistory() != (deque<string>){"a", "c", "b"}) return;
  if(cache.getCaches() != expectedCaches) return;

  cache.handleCache("d");
  expectedCaches = {
    {"a", make_pair("a", 1)},
    {"d", make_pair("d", 1)},
    {"c", make_pair("c", 1)}
  };
  if(cache.getHistory() != (deque<string>){"d", "a", "c"}) return;

  std::cout<<"OK"<<endl;
  return;
}
