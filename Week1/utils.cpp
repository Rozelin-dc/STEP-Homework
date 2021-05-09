#include "utils.h"

/** 外部ファイル読み込み */
vector<string> loadFile(string path) {
  std::ifstream ifs(path);
  if (ifs.fail()) {
    std::cerr << "Failed to open file." << std::endl;
    return {"error"};
  }
  string str;
  vector<string> contents(0);
  while (std::getline(ifs, str)) {
    contents.push_back(str);
  }
  return contents;
}