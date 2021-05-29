#include <bits/stdc++.h>
using namespace std;

/** そのページの名前とリンクづけられたページの id を値に持つ構造体 */
struct _pageData
{
  string name;
  vector<string> linkedPages;
};
typedef struct _pageData pageData_t;

unordered_map<string, pageData_t> readData();
