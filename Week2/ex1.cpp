#include <bits/stdc++.h>
using namespace std;

// 行列中に出現する値の最大値と最小値
#define MIN 0
#define MAX 100

vector<vector<int>> makeMatrix(int size, int seed);
vector<vector<int>> multMatrixes(int size, vector<vector<int>> a, vector<vector<int>> b);
void printMatrix(int size, vector<vector<int>> output);

int main() {
  int n;
  cin>>n;

  // 行列生成
  std::random_device rnd;
  vector<vector<int>> a = makeMatrix(n, rnd());
  vector<vector<int>> b = makeMatrix(n, rnd());

  clock_t start = clock(); // 計測開始

  vector<vector<int>> ans = multMatrixes(n, a, b);

  clock_t end = clock(); // 計測終了

  // デバッグ用出力
  // printMatrix(n, a);
  // cout<<endl;
  // printMatrix(n, b);
  // cout<<endl;
  // printMatrix(n, ans);

  // 結果を外部ファイルに出力
  const char fileName[] = "ex1-result.csv";
  std::ofstream ofs(fileName, ios::app);

  if (!ofs) {
    cout<< "ファイルが開けませんでした。" <<endl;
    return 1;
  }
  ofs<<n<<","<<(double)(end - start) / CLOCKS_PER_SEC<<endl;
  return 0;
}

/** seed に基づきランダムな size x size の行列を生成 */
vector<vector<int>> makeMatrix(int size, int seed) {
  vector<vector<int>> matrix(size, vector<int>(size));
  std::default_random_engine eng(seed);
  std::uniform_int_distribution<int> distr(MIN, MAX);

  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      matrix[i][j] = distr(eng);
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

/** 行列を出力 */
void printMatrix(int size, vector<vector<int>> output) {
  for (int i = 0; i < size; i++)
  {
    for (int j = 0; j < size; j++)
    {
      cout<<output[i][j]<<" ";
    }
    cout<<endl;
  }
  return;
}
