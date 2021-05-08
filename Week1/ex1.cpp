#include <bits/stdc++.h>
using namespace std;

vector<string> loadDictionary();
vector<vector<string>> createNewDictionary(vector<string> dictionary, int length);
vector<string> search(string word, vector<vector<string>> newDictionary);

int main() {
  vector<string> dictionary = loadDictionary();

  string input;
  cin>>input;

  vector<vector<string>> newDictionary = createNewDictionary(dictionary, input.length());
  // 新辞書ソート
  sort(newDictionary.begin(), newDictionary.end(),[](const vector<string> &alpha, const vector<string> &beta){return alpha[0] < beta[0];});

  string sortedInput = input;
  std::sort(sortedInput.begin(), sortedInput.end());
  vector<string> ans = search(sortedInput, newDictionary);
  for (int i = 0; i < (int)ans.size(); i++)
  {
    cout<<ans[i]<<endl;
  }
  return 0;
}

/** 辞書読み込み */
vector<string> loadDictionary() {
  std::ifstream ifs("./anagram/words.txt");
  if (ifs.fail()) {
    std::cerr << "Failed to open file." << std::endl;
    return {"error"};
  }
  string str;
  vector<string> dictionary(0);
  while (std::getline(ifs, str)) {
    dictionary.push_back(str);
  }
  return dictionary;
}

/** 入力された単語の長さに合わせて新辞書作成 */
vector<vector<string>> createNewDictionary(vector<string> dictionary, int length) {
  vector<vector<string>> newDictionary(0, vector<string>(2));
  for (int i = 0; i < (int)dictionary.size(); i++)
  {
    if ((int)dictionary[i].length() != length) continue;
    string str = dictionary[i];
    std::sort(str.begin(), str.end());
    newDictionary.push_back({ str, dictionary[i] });
  }
  return newDictionary;
}

/** アナグラム検索 */
vector<string> search(string word, vector<vector<string>> newDictionary) {
  bool found = false;
  int beginIdx = 0, endIdx = (int)newDictionary.size();
  int searchIdx;
  while(!found) {
    searchIdx = (endIdx - beginIdx) / 2;
    if(newDictionary[searchIdx][0] == word) {
      found = true;
      break;
    } else if(word.compare(newDictionary[searchIdx][0]) < 0) {
      endIdx = searchIdx - 1;
    } else {
      beginIdx = searchIdx + 1;
    }
    cout<<word.compare(newDictionary[searchIdx][0])<<beginIdx<<" "<<endIdx<<endl;
    if(endIdx <= beginIdx) {
      searchIdx = endIdx;
      break;
    }
  }
  vector<string> ans(0);
  int idx = searchIdx;
  while(newDictionary[idx][0] == word) {
    ans.push_back(newDictionary[idx][1]);
    idx--;
  }
  idx = searchIdx + 1;
  while(newDictionary[idx][0] == word) {
    ans.push_back(newDictionary[idx][1]);
    idx++;
  }
  return ans;
}
