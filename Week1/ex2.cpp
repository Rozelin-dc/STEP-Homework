#include <bits/stdc++.h>
#include "LoadDictionary.h"
using namespace std;

int main() {
  vector<string> dictionary = loadDictionary();
  for (int i = 0; i < 10; i++)
  {
    cout<<dictionary[i]<<endl;
  }
  
}
