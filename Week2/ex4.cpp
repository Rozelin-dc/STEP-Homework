#include <bits/stdc++.h>
using namespace std;

#define MAX 5 // 保存できるキャッシュの最大数

void handleCache(string currentUrl);
void doHistoryOrganizing();

/** Webページと history 中のURLの出現回数を値として持つ構造体 */
struct _siteData
{
  string web;
  int count;
};
typedef struct _siteData siteData_t;

std::deque<string> history; // 先頭に行くほど最近に訪れたURLが保存されている配列
std::unordered_map<string, siteData_t> caches; // URLをキー、siteData を値に持つハッシュテーブル

int main() {
  int n;
  cin>>n;

  string currentUrl; // 新しく訪れたURL

  for (int i = 0; i < n; i++) {
    cin>>currentUrl;
    handleCache(currentUrl);

    /* デバッグ用出力
    for (int i = 0; i < (int)history.size(); i++)
    {
      cout<<caches[history[i]].web<<","<<caches[history[i]].count<<endl;
    } */
  }
}

void handleCache(string currentUrl) {
  // currentUrl が caches に含まれるか検索
  auto itr = caches.find(currentUrl);
  if (itr != caches.end()) { // currentUrl が caches に含まれていた場合
    if(history[0] == currentUrl) return;

    history.push_front(currentUrl);
    caches.at(currentUrl).count += 1;

    doHistoryOrganizing();
    return;
  } else { // currentUrl が caches に含まれていない場合
    if(caches.size() < MAX) { // 保存できるキャッシュにまだ余裕がある時
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
void doHistoryOrganizing() {
  string historyEndUrl = history[history.size()- 1]; // history の末尾のURL
  while (caches.at(historyEndUrl).count >= 2)
  {
    caches.at(historyEndUrl).count -= 1;
    history.pop_back();
    historyEndUrl = history[history.size() - 1];
  }
  return;
}
