#include <climits>
#include <iostream>
using namespace std;

void printMTable(int **m, int n) {
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      cout << m[i][j] << " ";
    }
    cout << endl;
  }
}

int chilMul(int *p, int n) {
  int **m = new int *[n];
  for (int i = 0; i < n; i++)
    m[i] = new int[n];

  for (int i = 0; i < n; i++)
    m[i][i] = 0;

  for (int L = 2; L < n; L++) {
    for (int i = 1; i < n - L + 1; i++) {
      int j = i + L - 1;
      m[i][j] = INT_MAX;

      for (int k = i; k < j; k++) {
        int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
        if (q < m[i][j])
          m[i][j] = q;
      }
    }
  }

  printMTable(m, n);

  return m[1][n - 1];
}

int main() {
  int arr[] = {4, 2, 3, 4, 5};
  int size = sizeof(arr) / sizeof(arr[0]);
  int m = chilMul(arr, size);
  cout << "Minimum number of multiplications is " << m << endl;
  return 0;
}
