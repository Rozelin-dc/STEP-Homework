#include <bits/stdc++.h>
using namespace std;

// 行列中に出現する値の最大値と最小値
#define MIN_MATRIX_COMPONENT 0
#define MAX_MATRIX_COMPONENT 100

void makeMatrix(int size, int seed, int *matrix);
void multMatrixes(int size, int *a, int *b, int *ans);

int main() {
  int n;
  cin>>n;

  // 行列生成
  std::random_device rnd;
  int a[n][n];
  makeMatrix(n, rnd(), *a);
  int b[n][n];
  makeMatrix(n, rnd(), *b);

  clock_t start = clock(); // 計測開始

  int ans[n][n];
  multMatrixes(n, *a, *b, *ans);

  clock_t end = clock(); // 計測終了

  cout<<(double)(end - start) / CLOCKS_PER_SEC<<"[sec]"<<endl;

  return 0;
}

/** seed に基づきランダムな size x size の行列を生成 */
void makeMatrix(int size, int seed, int *matrix) {
  std::default_random_engine eng(seed);
  std::uniform_int_distribution<int> distr(MIN_MATRIX_COMPONENT, MAX_MATRIX_COMPONENT);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      *(matrix + (i * size) + j) = distr(eng);
    }
  }
  return;
}

/** A×Bを計算 */
void multMatrixes(int size, int *a, int *b, int *ans) {
  for (int k = 0; k < size; k++) {
    for (int j = 0; j < size; j++) {
      for (int i = 0; i < size; i++) {
        *(ans + (i * size) + j) += *(a + (i * size) + k) * *(b + (k * size) + j);
      }
    }
  }
  return;
}
