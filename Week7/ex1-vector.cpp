#include <bits/stdc++.h>
using namespace std;

// 行列中に出現する値の最大値と最小値
#define MIN_MATRIX_COMPONENT 0
#define MAX_MATRIX_COMPONENT 100

vector<vector<int>> makeMatrix(int size, int seed);
vector<vector<int>> multMatrixes(int size, vector<vector<int>> a, vector<vector<int>> b);
void test();

int main() {
  test();

  int n;
  cin>>n;

  // 行列生成
  std::random_device rnd;
  vector<vector<int>> a = makeMatrix(n, rnd());
  vector<vector<int>> b = makeMatrix(n, rnd());

  clock_t start = clock(); // 計測開始

  vector<vector<int>> ans = multMatrixes(n, a, b);

  clock_t end = clock(); // 計測終了

  cout<<(double)(end - start) / CLOCKS_PER_SEC<<"[sec]"<<endl;

  return 0;
}

/** seed に基づきランダムな size x size の行列を生成 */
vector<vector<int>> makeMatrix(int size, int seed) {
  vector<vector<int>> matrix(size, vector<int>(size));
  std::default_random_engine eng(seed);
  std::uniform_int_distribution<int> distr(MIN_MATRIX_COMPONENT, MAX_MATRIX_COMPONENT);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      matrix[i][j] = distr(eng);
    }
  }
  return matrix;
}

/** A×Bを計算 */
vector<vector<int>> multMatrixes(int size, vector<vector<int>> a, vector<vector<int>> b) {
  vector<vector<int>> ans(size, vector<int>(size));
  for (int k = 0; k < size; k++) {
    for (int j = 0; j < size; j++) {
      for (int i = 0; i < size; i++) {
        ans[i][j] += a[i][k] * b[k][j];
      }
    }
  }
  return ans;
}

void test() {
  vector<vector<int>> a = {
    {1, 2},
    {3, 4}
  };
  vector<vector<int>> b = {
    {5, 6},
    {7, 8}
  };
  vector<vector<int>> ans = {
    {19, 22},
    {43, 50}
  };
  vector<vector<int>> result = multMatrixes(2, a, b);
  if(result != ans) return;

  a = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9}
  };
  b = {
    {10, 11, 12},
    {13, 14, 15},
    {16, 17, 18}
  };
  ans = {
    {84, 90, 96},
    {201, 216, 231},
    {318, 342, 366}
  };
  result = multMatrixes(3, a, b);
  if(result != ans) return;

  cout<<"OK"<<endl;
  return;
}
