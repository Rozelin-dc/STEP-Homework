#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

vector<vector<string>> createNewDictionary(int length);
vector<string> findAnagram(string inputPath);
int calculateScore(string word);

const vector<string> dictionary = loadFile("./anagram/words.txt");

int main() {

}

/** 入力された単語の長さに合わせて新辞書作成 */
vector<vector<string>> createNewDictionary(int length) {
  vector<vector<string>> newDictionary(0, vector<string>(2));
  for (int i = 0; i < (int)dictionary.size(); i++)
  {
    if ((int)dictionary[i].length() > length) continue;
    string str = dictionary[i];
    std::sort(str.begin(), str.end());
    newDictionary.push_back({ str, dictionary[i] });
  }
  return newDictionary;
}

/** 入力に合わせたアナグラムを検索 */
vector<string> findAnagram(string inputPath) {
  vector<string> inputs = loadFile(inputPath);
  vector<vector<string>> newDictionary = createNewDictionary(inputs[0].length());
}

/** score_checker.py の calculate_score を移植 */
int calculateScore(string word) {
  const int scores[] = { 1, 3, 2, 2, 1, 3, 3, 1, 1, 4, 4, 2, 2, 1, 1, 3, 4, 1, 1, 1, 2, 3, 3, 4, 3, 4 };
  int score = 0;
  for (int i = 0; i < word.length(); i++)
  {
    score += scores[word[i] - 'a'];
  }
  return score;
}
