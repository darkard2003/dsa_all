#include <algorithm>
#include <iostream>

using namespace std;

void swap(int &a, int &b) {
  int t = a;
  a = b;
  b = t;
}

// bubble sort
void bsort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    bool sorted = true;
    for (int j = n - 1; j > i; j--) {
      if (arr[j] < arr[j - 1]) {
        swap(arr[j], arr[j - 1]);
        sorted = false;
      }
    }
    if (sorted) {
      break;
    }
  }
}

// selection sort
void ssort(int *arr, int n) {
  for (int i = 0; i < n; i++) {
    int min = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
    }
    swap(arr[i], arr[min]);
  }
}

// insertion sort
void isort(int *arr, int n) {
  for (int i = 1; i < n; i++) {
    int j = i;
    int t = arr[i];
    while (j > 0 && arr[j - 1] > t) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = t;
  }
}

// Merge sort
void merge(int *arr, int *tmp, int l, int m, int r) {
  int i = l;
  int j = m;
  int k = l;
  while (i < m && j < r) {
    if (arr[i] < arr[j]) {
      tmp[k++] = arr[i++];
    } else {
      tmp[k++] = arr[j++];
    }
  }
  while (i < m) {
    tmp[k++] = arr[i++];
  }
  while (j < r) {
    tmp[k++] = arr[j++];
  }
  for (int i = l; i < r; i++) {
    arr[i] = tmp[i];
  }
}

void msort(int *arr, int *tmp, int l, int r) {
  if (r - l > 1) {
    int m = l + (r - l) / 2;
    msort(arr, tmp, l, m);
    msort(arr, tmp, m, r);
    merge(arr, tmp, l, m, r);
  }
}

int parition(int *arr, int l, int r) {
  int pivot = arr[r - 1];
  int i = l;
  for (int j = l; j < r; j++) {
    if (arr[j] < pivot) {
      swap(arr[i++], arr[j]);
    }
  }
  swap(arr[i], arr[r - 1]);
  return i;
}

void qsort(int *arr, int l, int r) {
  if (r - l > 1) {
    int p = parition(arr, l, r);
    qsort(arr, l, p);
    qsort(arr, p + 1, r);
  }
}
