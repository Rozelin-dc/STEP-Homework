#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

vector<string> findAnagrams(string inputPath);
void createNewDictionary(int length);
vector<string> search(string word);
bool isSubset(vector<int> inputMap, vector<int> wordMap);
string findBestAnagram(vector<string> anagrams);
int calculateScore(string word);
void output(const char *fileName, vector<string> contents);

const vector<string> dictionary = loadFile("./anagram/words.txt");
vector<string> newDictionary(0);
vector<vector<int>> wordsMap(0, vector<int>(26));

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
  createNewDictionary(inputs[0].length());

  vector<string> ans(0);

  for (int i = 0; i < (int)inputs.size(); i++)
  {
    vector<string> anagrams = search(inputs[i]);
    string bestAnagram = findBestAnagram(anagrams);
    ans.push_back(bestAnagram);
  }
  return ans;
}

/** 入力された単語の長さに合わせて新辞書作成 */
void createNewDictionary(int length) {
  for (int i = 0; i < (int)dictionary.size(); i++)
  {
    if ((int)dictionary[i].length() > length) continue;

    string str = dictionary[i];
    newDictionary.push_back({ str });

    vector<int> wordMap(26);
    for (int i = 0; i < (int)str.length(); i++)
    {
      wordMap[str[i] - 'a'] += 1;
    }
    wordsMap.push_back(wordMap);
  }
  return;
}

vector<string> search(string word) {
  vector<int> inputMap(26);
  for (int i = 0; i < (int)word.length(); i++)
  {
    inputMap[word[i] - 'a'] += 1;
  }

  vector<string> ans(0);

  for (int i = 0; i < (int)newDictionary.size(); i++)
  {
    if(isSubset(inputMap, wordsMap[i])) ans.push_back(newDictionary[i]);
  }
  return ans;
}

/** 第二引数の配列が第一引数の配列のサブセットになっているか */
bool isSubset(vector<int> inputMap, vector<int> wordMap) {
  for (int i = 0; i < 26; i++)
  {
    if(inputMap[i] < wordMap[i]) return false;
  }
  return true;
}

/** 見つかったアナグラムの中からベストスコアのものを抽出 */
string findBestAnagram(vector<string> anagrams) {
  string ans;
  int bestScore = 0;
  for (int i = 0; i < (int)anagrams.size(); i++)
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
