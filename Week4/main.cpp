#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

deque<string> findSortestPath(unordered_map<string, pageData_t>& links, string start, string end);
string findTargetId(unordered_map<string, pageData_t>& links, string targetName);

int main() {
  unordered_map<string, pageData_t> links = {}; // ページの id をキー、名前とリンク先を値として持つ
  readData(links);
  deque<string> foundPath = findSortestPath(links, "Google", "渋谷");
  deque<string> emptyDeque = {};
  if (foundPath == emptyDeque) {
    cout<<"Not Found"<<endl;
    return 1;
  }
  
  cout<<"found!"<<endl;
  for (int i = 0; i < (int)foundPath.size(); i++)
  {
    cout<<foundPath[i]<<endl;
  }
  return 0;
}

/** links 内に start と end を繋げるパスがあるか探し、見つかったら最短経路のパスを返す */
deque<string> findSortestPath(unordered_map<string, pageData_t>& links, string start, string end) {
  if (start == end) return {start};

  string startId = findTargetId(links, start);
  if (startId == "Not Found") return {};

  unordered_map<string, string> visitedPages = {}; // 訪れたページをキー、どのページから来たかを値として持つ
  deque<string> queue = {startId}; // ページの id が保存されているキュー
  bool found = false;
  while (queue.size() > 0)
  {
    if (links.at(queue[0]).name == end) {
      found = true;
      break;
    }
    for (int i = 0; i < (int)links.at(queue[0]).linkedPages.size(); i++)
    {
      string linkedPageId = links.at(queue[0]).linkedPages[i];
      string linkedPageName = links.at(linkedPageId).name;
      auto itr = visitedPages.find(linkedPageName);
      if (itr == visitedPages.end()) { // キューのリンク先がまだ訪れていないページだったら
        visitedPages[linkedPageName] = links.at(queue[0]).name;
        queue.push_back(linkedPageId);
      }
    }
    queue.pop_front();
  }

  if (!found) return {};

  deque<string> foundPath = {end};
  while (foundPath[0] != start)
  {
    foundPath.push_front(visitedPages.at(foundPath[0]));
  }

  return foundPath;
}

/** links 内で名前が targetName のページの id を探す */
string findTargetId(unordered_map<string, pageData_t>& links, string targetName) {
  for (auto itr = links.begin(); itr != links.end(); ++itr)
  {
    if (itr->second.name == targetName) return itr->first;
  }
  return "Not Found";
}
