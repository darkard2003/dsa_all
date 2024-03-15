#include <iostream>

using namespace std;

int fmin(int a, int b) { return a < b ? a : b; }
int fmax(int a, int b) { return a < b ? b : a; }

class MinMax {
public:
  int min;
  int max;

  MinMax(int min, int max) {
    this->min = min;
    this->max = max;
  }
};

MinMax getMinMax(int *arr, int l, int h) {
  if (l >= h)
    return MinMax(arr[l], arr[l]);
  int min, max;
  if (l == h - 1) {
    if (arr[l] > arr[h]) {
      min = arr[h];
      max = arr[l];
    } else {
      min = arr[l];
      max = arr[h];
    }
    return MinMax(min, max);
  }

  int m = (l + h) / 2;

  MinMax m1 = getMinMax(arr, l, m);
  MinMax m2 = getMinMax(arr, m + 1, h);

  min = fmin(m1.min, m2.min);
  max = fmax(m1.max, m2.max);

  return MinMax(min, max);
}

int main() {
  int n;
  cout << "Enter the size and array: ";
  cin >> n;

  int *arr = new int[n];

  cout << "Enter the values: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  MinMax m = getMinMax(arr, 0, n - 1);

  cout << "Min: " << m.min << endl << "Max: " << m.max << endl;

  return 0;
}
