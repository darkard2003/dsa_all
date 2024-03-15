#include <iostream>

using namespace std;

void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}

void merge(int *arr, int l, int m, int r){
  int n = r - l + 1;
  int *tarr = new int[n];

  int i = l, j=m+1, k=0;

  while(i<=m && j<=r && k <n){
    if(arr[i] < arr[j])
      tarr[k++] = arr[i++];
    else
      tarr[k++] = arr[j++];
  }

  while(i<=m)
    tarr[k++] = arr[i++];
  
  while(j<=r)
    tarr[k++] = arr[j++];
  
  for(i=0; i<n; i++)
    arr[l+i] = tarr[i];
}

void msort(int *arr, int l, int r){
  if(l>=r) return;
  if(l == r-1){
    if(arr[l] > arr[r]) swap(arr[l], arr[r]);
    return;
  }

  int m = (l+r)/2;
  msort(arr, l, m);
  msort(arr, m+1, r);

  merge(arr, l, m, r);
}

int main(){
  int n;
  cout << "Enter the size: ";
  cin >> n;
  int *arr = new int[n];

  cout << "Enter the elements: ";
  for(int i=0; i<n; i++)
    cin >> arr[i];

  msort(arr, 0, n-1);

  for(int i=0; i<n; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}
