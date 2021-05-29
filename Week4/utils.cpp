#include "utils.h"

unordered_map<string, pageData_t> readData() {
  unordered_map<string, pageData_t> links = {};

  // id と名前のセットを読み込み
  std::ifstream pages("./wikipedia_data/pages_small.txt");
  if (pages.fail()) {
    cerr<<"Failed to open file."<<endl;
    return {};
  }
  string str;
  while (std::getline(pages, str)) {
    auto index = str.find('\t');
    auto id = str.substr(0, index);
    auto title = str.substr(index + 1, str.size() - id.size() - 1);
    links[id] = {title, {}};
  }
  pages.close();

  // id とリンク先のセットを読み込み
  std::ifstream ifs("./wikipedia_data/links_small.txt");
  if (ifs.fail()) {
    cerr<<"Failed to open file."<<endl;
    return {};
  }
  while (std::getline(ifs, str)) {
    auto index = str.find('\t');
    auto from = str.substr(0, index);
    auto to = str.substr(index + 1, str.size() - from.size() - 1);
    links[from].linkedPages.push_back(to);
  }
  ifs.close();

  return links;
}
