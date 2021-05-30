#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

deque<string> findSortestPath(unordered_map<string, pageData_t>& links, string start, string end);
string findTargetId(unordered_map<string, pageData_t>& links, string targetName);

int main() {
  unordered_map<string, pageData_t> links = {}; // �y�[�W�� id ���L�[�A���O�ƃ����N���l�Ƃ��Ď���
  readData(links);
  deque<string> foundPath = findSortestPath(links, "Google", "�a�J");
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

/** links ���� start �� end ���q����p�X�����邩�T���A����������ŒZ�o�H�̃p�X��Ԃ� */
deque<string> findSortestPath(unordered_map<string, pageData_t>& links, string start, string end) {
  if (start == end) return {start};

  string startId = findTargetId(links, start);
  if (startId == "Not Found") return {};

  unordered_map<string, string> visitedPages = {}; // �K�ꂽ�y�[�W���L�[�A�ǂ̃y�[�W���痈������l�Ƃ��Ď���
  deque<string> queue = {startId}; // �y�[�W�� id ���ۑ�����Ă���L���[
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
      if (itr == visitedPages.end()) { // �L���[�̃����N�悪�܂��K��Ă��Ȃ��y�[�W��������
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

/** links ���Ŗ��O�� targetName �̃y�[�W�� id ��T�� */
string findTargetId(unordered_map<string, pageData_t>& links, string targetName) {
  for (auto itr = links.begin(); itr != links.end(); ++itr)
  {
    if (itr->second.name == targetName) return itr->first;
  }
  return "Not Found";
}
