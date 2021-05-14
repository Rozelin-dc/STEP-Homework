#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> makeMatrix(int size);
vector<vector<int>> multMatrixes(int size, vector<vector<int>> a, vector<vector<int>> b);
void printMatrix(int size, vector<vector<int>> output);

int main() {
  clock_t start = clock(); // 計測開始

  int n;
  cin>>n;
  vector<vector<int>> a = makeMatrix(n);
  vector<vector<int>> b = makeMatrix(n);
  vector<vector<int>> ans = multMatrixes(n, a, b);

  clock_t end = clock(); // 計測終了

  // デバッグ用出力
  printMatrix(n, a);
  cout<<endl;
  printMatrix(n, b);
  cout<<endl;
  printMatrix(n, ans);

  // 結果を外部ファイルに出力
  const char fileName[] = "result.csv";
  std::ofstream ofs(fileName, ios::app);

  if (!ofs) {
    cout<< "ファイルが開けませんでした。" <<endl;
    return 1;
  }
  ofs<<n<<","<<(double)(end - start) / CLOCKS_PER_SEC<<endl;
}

vector<vector<int>> makeMatrix(int size) {
  vector<vector<int>> matrix(size, vector<int>(size));
  std::random_device random;
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      matrix[i][j] = random();
    }
  }
  return matrix;
}

/** A×Bを計算 */
vector<vector<int>> multMatrixes(int size, vector<vector<int>> a, vector<vector<int>> b) {
  vector<vector<int>> ans(size, vector<int>(size));
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      for (int k = 0; k < size; k++)
      {
        ans[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return ans;
}

void printMatrix(int size, vector<vector<int>> output) {
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout<<output[i][j];
    }
    cout<<endl;
  }
  return;
}
