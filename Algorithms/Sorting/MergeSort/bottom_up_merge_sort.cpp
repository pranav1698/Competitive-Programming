// Bottom Up Merge Sort C Implementation
// SlothyCoder16
// August 04, 2020

#include <bits/stdc++.h>
using namespace std;

void merge(int* a, int lo, int mid, int high) {
  int* aux = new int[high - lo + 1];
  for(int c=lo; c<=high; c++)
    aux[c] = a[c];

    int i=lo;
    int j=mid;
    int k=lo;

    while(i<mid && j<=high) {
      if(aux[i]<=aux[j]) {
        a[k] = aux[i];
        i++;
        k++;
      } else {
        a[k] = aux[j];
        j++;
        k++;
      }
    }

    while(i<mid){
      a[k] = aux[i];
      k++;
      i++;
    }

    while(j<=high) {
      a[k] = aux[j];
      k++;
      j++;
    }
}

void MergeSort(int* a, int lo, int high) {
  int N = (high - lo) + 1;
  for(int sz=1; sz<N; sz = sz + sz)
    for(int start=0; start<N-sz; start += sz+sz)
      merge(a, start, start+sz, min(start + sz + sz -1, N-1));
}

int main() {
  int a[6] = {40, 20, 60, 10, 50, 30};
  MergeSort(a, 0, 5);

  for(int i=0; i<6; i++)
    cout << a[i] << endl;
}
