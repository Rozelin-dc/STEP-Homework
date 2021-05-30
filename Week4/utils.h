#include <bits/stdc++.h>
using namespace std;

/** そのページの名前とリンクづけられたページの id を値に持つ構造体 */
typedef struct
{
  string name;
  deque<string> linkedPages;
} pageData_t;

void readData(unordered_map<string, pageData_t>& links);
