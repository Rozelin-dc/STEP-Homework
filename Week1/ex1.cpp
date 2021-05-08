#include <bits/stdc++.h>
using namespace std;

void loadDictionary(vector<string> dictionary);

int main() {
  vector<string> dictionary(0);
  loadDictionary(dictionary);
}

void loadDictionary(vector<string> dictionary) {
  std::ifstream ifs("./anagram/words.txt");
  if (ifs.fail()) {
    std::cerr << "Failed to open file." << std::endl;
    return;
  }
  string str;
  while (getline(ifs, str)) {
    dictionary.push_back(str);
  }
}
