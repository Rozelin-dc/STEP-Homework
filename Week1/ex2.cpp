#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

vector<string> findAnagram(string inputPath);
vector<vector<string>> createNewDictionary(int length);
vector<string> search(string word, vector<vector<string>> newDictionary);
string findBestAnagram(vector<string> anagrams);
int calculateScore(string word);

const vector<string> dictionary = loadFile("./anagram/words.txt");

int main() {

}

/** 入力に合わせたアナグラムを検索 */
vector<string> findAnagram(string inputPath) {
  vector<string> inputs = loadFile(inputPath);
  vector<vector<string>> newDictionary = createNewDictionary(inputs[0].length());

  vector<string> ans(0);

  for (int i = 0; i < inputs.size(); i++)
  {
    vector<string> anagrams = search(inputs[i], newDictionary);
    string bestAnagram = findBestAnagram(anagrams);
    ans.push_back(bestAnagram);
  }
  return ans;
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
  sort(newDictionary.begin(), newDictionary.end(), [](const vector<string> &alpha, const vector<string> &beta){return alpha[0] < beta[0];});
  return newDictionary;
}

vector<string> search(string word, vector<vector<string>> newDictionary) {

}

/** 見つかったアナグラムの中からベストスコアのものを抽出 */
string findBestAnagram(vector<string> anagrams) {
  string ans;
  int bestScore = 0;
  for (int i = 0; i < anagrams.size(); i++)
  {
    if(calculateScore(anagrams[i]) > bestScore) {
      ans = anagrams[i];
      bestScore = calculateScore(anagrams[i]);
    }
  }
  return ans;
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
