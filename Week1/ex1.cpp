#include <bits/stdc++.h>
using namespace std;

vector<string> loadDictionary();
vector<vector<string>> createNewDictionary(vector<string> dictionary, int length);
vector<string> search(string word, vector<vector<string>> newDictionary);

int main() {
  vector<string> dictionary = loadDictionary();
  for (int i = 0; i < 10; i++)
  {
    cout<<dictionary[i]<<endl;
  }
  string input;
  cin>>input;
  vector<vector<string>> newDictionary = createNewDictionary(dictionary, input.length());
  for (int i = 0; i < 20; i++)
  {
    cout<<newDictionary[i][0]<<" "<<newDictionary[i][1]<<endl;
  }
  cout<<"sort"<<endl;
  sort(newDictionary.begin(), newDictionary.end(),[](const vector<string> &alpha, const vector<string> &beta){return alpha[0] < beta[0];});
  for (int i = 0; i < 20; i++)
  {
    cout<<newDictionary[i][0]<<" "<<newDictionary[i][1]<<endl;
  }
  string sortedInput = input;
  std::sort(sortedInput.begin(), sortedInput.end());
  vector<string> ans = search(sortedInput, newDictionary);
  for (int i = 0; i < (int)ans.size(); i++)
  {
    cout<<ans[i]<<endl;
  }
  return 0;
}

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

vector<string> search(string word, vector<vector<string>> newDictionary) {
  bool found = false;
  int begin = 0, end = (int)newDictionary.size();
  int idx;
  while(!found) {
    idx = (end - begin) / 2;
    if(newDictionary[idx][0] == word) {
      found = true;
    } else if(newDictionary[idx][0] > word) {
      end = idx - 1;
    } else {
      begin = idx + 1;
    }
    if(end >= begin) {
      idx = end;
      break;
    }
  }
  vector<string> ans(0);
  int searchIdx = idx;
  while(newDictionary[searchIdx][0] == word) {
    ans.push_back(newDictionary[searchIdx][1]);
    searchIdx--;
  }
  searchIdx = idx + 1;
  while(newDictionary[searchIdx][0] == word) {
    ans.push_back(newDictionary[searchIdx][1]);
    searchIdx++;
  }
  return ans;
}
