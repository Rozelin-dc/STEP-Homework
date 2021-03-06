#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

vector<vector<string>> createDictionaryWithLength(int length);
int findIndexOfAnagram(string word, vector<vector<string>> newDictionary);

const vector<string> dictionary = loadFile("./anagram/words.txt");

int main() {
  string input;
  cin>>input;

  vector<vector<string>> newDictionary = createDictionaryWithLength(input.length());

  string sortedInput = input;
  std::sort(sortedInput.begin(), sortedInput.end());
  int findIdx = findIndexOfAnagram(sortedInput, newDictionary);

  vector<string> ans(0);
  if(findIdx != -1) {
    int idx = findIdx;
    while(newDictionary[idx][0] == sortedInput) {
      ans.push_back(newDictionary[idx][1]);
      idx--;
    }
    idx = findIdx + 1;
    while(newDictionary[idx][0] == sortedInput) {
      ans.push_back(newDictionary[idx][1]);
      idx++;
    }
  }

  for (int i = 0; i < (int)ans.size(); i++)
  {
    if(ans[i] == input) continue;
    cout<<ans[i]<<endl;
  }
  return 0;
}

/** 入力された単語の長さに合わせて新辞書作成 */
vector<vector<string>> createDictionaryWithLength(int length) {
  vector<vector<string>> newDictionary(0, vector<string>(2));
  for (int i = 0; i < (int)dictionary.size(); i++)
  {
    if ((int)dictionary[i].length() != length) continue;

    string str = dictionary[i];
    std::sort(str.begin(), str.end());
    newDictionary.push_back({ str, dictionary[i] });
  }
  // ソートされた単語を元にソート
  sort(newDictionary.begin(), newDictionary.end(),[](const vector<string> &alpha, const vector<string> &beta){return alpha[0] < beta[0];});
  return newDictionary;
}

/** アナグラム検索 */
int findIndexOfAnagram(string word, vector<vector<string>> newDictionary) {
  int beginIdx = 0;
  int endIdx = (int)newDictionary.size() - 1;
  int searchIdx = (endIdx - beginIdx) / 2;
  while(beginIdx <= endIdx) {
    searchIdx = ((endIdx - beginIdx) / 2) + beginIdx;

    if(newDictionary[searchIdx][0] == word) {
      return searchIdx;
    } else if(word.compare(newDictionary[searchIdx][0]) < 0) {
      endIdx = searchIdx - 1;
    } else {
      beginIdx = searchIdx + 1;
    }
  }
  return -1;
}
