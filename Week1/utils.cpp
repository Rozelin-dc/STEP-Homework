#include "utils.h"

/** 辞書読み込み */
vector<string> loadFile(string path) {
  std::ifstream ifs(path);
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