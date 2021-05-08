#include <bits/stdc++.h>
using namespace std;

vector<string> loadDictionary();
vector<vector<string>> createNewDictionary(vector<string> dictionary, int length);

int main() {
  vector<string> dictionary = loadDictionary();
  for (int i = 0; i < 10; i++)
  {
    cout<<dictionary[i]<<endl;
  }
  string input;
  cin>>input;
  vector<vector<string>> newDictionary = createNewDictionary(dictionary, input.length());
  for (int i = 0; i < 10; i++)
  {
    cout<<newDictionary[i][0]<<" "<<newDictionary[i][1]<<endl;
  }
  
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
  for (int i = 0; i < dictionary.size(); i++)
  {
    if (dictionary[i].length() != length) continue;
    string str = dictionary[i];
    std::sort(str.begin(), str.end());
    newDictionary.push_back({ str, dictionary[i] });
  }
  return newDictionary;
}
