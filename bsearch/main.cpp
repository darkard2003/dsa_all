#include<iostream>

using namespace std;

int bsearch(int *arr, int l, int h, int k){
  if(l >= h){
    if(arr[l] == k) return l;
    return -1;
  }
  int m = (l+h)/2;

  if(arr[m] == k) return m;
  if(arr[m] < k) return bsearch(arr, l, m-1, k);
  return bsearch(arr, m+1, h, k);
}

int main(){
  int n, k;

  cout << "Enter the size of the array: ";
  cin >> n;

  int *arr = new int[n];

  cout << "Enter the array: ";
  for(int i=0; i<n; i++)
    cin >> arr[i];

  cout << "Enter the key: ";
  cin >> k;

  int p = bsearch(arr, 0, n-1, k);

  if(p < 0) cout << "Element not found" << endl;
  else cout << "Element found at position: " << p << endl;

  return 0;
}
