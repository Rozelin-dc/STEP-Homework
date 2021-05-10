#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

vector<string> findAnagrams(string inputPath);
void filterDictionary(int length);
string search(string word);
bool isAnagram(vector<int> inputMap, string word);
int calculateScore(string word);
void output(const char *fileName, vector<string> contents);

const vector<string> dictionary = loadFile("./anagram/words.txt");

/** 入力の長さに合わせてフィルターをかけた辞書 */
vector<string> filteredDictionary(0);

/** ある単語のスコアと、その単語の filteredDictionary でのインデックスを値に持つ */
vector<vector<int>> wordsMap(0, vector<int>(2));

int main() {
  vector<string> ans;
  
  const char *outputPath1 = "./anagram/small-answer.txt";
  ans = findAnagrams("./anagram/small.txt");
  output(outputPath1, ans);

  const char *outputPath2 = "./anagram/medium-answer.txt";
  ans = findAnagrams("./anagram/medium.txt");
  output(outputPath2, ans);

  const char *outputPath3 = "./anagram/large-answer.txt";
  ans = findAnagrams("./anagram/large.txt");
  output(outputPath3, ans);
  
  return 0;
}

/** 入力に合わせたアナグラムを検索 */
vector<string> findAnagrams(string inputPath) {
  vector<string> inputs = loadFile(inputPath);
  filterDictionary(inputs[0].length());

  vector<string> ans(0);

  for (int i = 0; i < (int)inputs.size(); i++)
  {
    string anagram = search(inputs[i]);
    ans.push_back(anagram);
  }
  return ans;
}

/** 入力された単語の長さに合わせて辞書をフィルター */
void filterDictionary(int length) {
  filteredDictionary = {};
  wordsMap = {};
  for (int i = 0; i < (int)dictionary.size(); i++)
  {
    string str = dictionary[i];

    if ((int)str.length() > length) continue;

    filteredDictionary.push_back({ str });

    int idx = (int)filteredDictionary.size() - 1;
    int score = calculateScore(str);

    wordsMap.push_back({ score, idx });
  }

  sort(wordsMap.begin(), wordsMap.end(),[](const vector<int> &alpha, const vector<int> &beta){return alpha[0] > beta[0];});

  return;
}

string search(string word) {
  vector<int> inputMap(26);
  for (int i = 0; i < (int)word.length(); i++)
  {
    inputMap[word[i] - 'a'] += 1;
  }

  for (int i = 0; i < (int)filteredDictionary.size(); i++)
  {
    string str = filteredDictionary[wordsMap[i][1]];
    if(isAnagram(inputMap, str)) return str;
  }
  return "Not Found";
}

/** 第二引数の単語が第一引数のアルファベット使用数で表せるか */
bool isAnagram(vector<int> inputMap, string word) {
  for (int i = 0; i < (int)word.length(); i++)
  {
    inputMap[word[i] - 'a'] -= 1;
  }
  std::sort(inputMap.begin(), inputMap.end());

  if(inputMap[0] < 0) return false;

  return true;
}

/** score_checker.py の calculate_score を移植 */
int calculateScore(string word) {
  const int scores[] = { 1, 3, 2, 2, 1, 3, 3, 1, 1, 4, 4, 2, 2, 1, 1, 3, 4, 1, 1, 1, 2, 3, 3, 4, 3, 4 };
  int score = 0;
  for (int i = 0; i < (int)word.length(); i++)
  {
    score += scores[word[i] - 'a'];
  }
  return score;
}

/** 外部ファイルへの書き出し */
void output(const char *fileName, vector<string> contents) {
  std::ofstream ofs(fileName);

  if (!ofs) {
    cout<< "ファイルが開けませんでした。" <<endl;
    return;
  }

  for (int i = 0; i < (int)contents.size(); i++)
  {
    ofs<<contents[i]<<endl;
  }
  return;
}
