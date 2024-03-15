#include <iostream>

using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

int getPartition_L(int *arr, int l, int r){
  int p = arr[r];
  int i = l-1;

  for(int j=l; j<r; j++)
    if(arr[j] < p)
      swap(arr[++i], arr[j]);

  swap(arr[++i], arr[r]);

  return i;
}

int getPartition_H(int *arr, int l, int r){
  int p = arr[l];
  int i = l;
  int j = r+1;
  while(1){
    while(arr[++i] < p);
    while(arr[--j] > p);
    if(i >= j){
      break;
    }
    swap(arr[i], arr[j]);
  }
  swap(arr[j], arr[l]);
  return j;
}

void qsort(int *arr, int l, int r){
  if(l >= r) return;

  int p = getPartition_H(arr, l, r);
  qsort(arr, l, p-1);
  qsort(arr, p+1, r);
}

int main(){
  int n;
  cout << "Enter the size: ";
  cin >> n;

  int *arr = new int[n];
  cout << "Enter the elements: ";
  for(int i=0; i<n; i++)
    cin >> arr[i];

  qsort(arr, 0, n-1);
  
  for(int i=0; i<n; i++)
    cout << arr[i] << " ";
  
  cout << endl;

  return 0;
}
