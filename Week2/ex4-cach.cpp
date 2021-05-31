#include "ex4-cach.h"

void Cache::handleCache(string currentUrl) {
  // currentUrl が caches に含まれるか検索
  auto itr = caches.find(currentUrl);
  if (itr != caches.end()) { // currentUrl が caches に含まれていた場合
    if(history[0] == currentUrl) {
      removeUnnecessaryHistory();
      return;
    }

    history.push_front(currentUrl);
    caches.at(currentUrl).second += 1;

    removeUnnecessaryHistory();
    return;
  } else { // currentUrl が caches に含まれていない場合
    if(caches.size() < MAX_CACHE_SIZE) { // 保存できるキャッシュにまだ余裕がある時
      history.push_front(currentUrl);
      caches[currentUrl] = make_pair(currentUrl, 1);
      return;
    }

    removeUnnecessaryHistory();
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
void Cache::removeUnnecessaryHistory() {
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
