#include <bits/stdc++.h>
#include "utils.h"
using namespace std;

int main() {
  unordered_map<string, pageData_t> links = readData();
  cout<<links["457783"].name<<", "<<links["457783"].linkedPages[0]<<endl;
}
