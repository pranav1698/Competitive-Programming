// Implementation of quick sort in c++
// SlothyCoder16
// August 05, 2020

#include <bits/stdc++.h>
using namespace std;

void swap(int* arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}


int partition(int* arr, int lo, int high) {
  int i= lo+1;
  int j = high;

  while(true) {
    while(arr[i] <= arr[lo]) {
      i++;
    }
    while(arr[j] > arr[lo]) {
      j--;
    }

    if(i>=j) break;
    swap(arr, i, j);
  }

  swap(arr, lo, j);

  return j;
}

void sort(int* arr, int lo, int high) {
  if(lo >= high) return;

  int j = partition(arr, lo, high);

  sort(arr, lo, j-1);
  sort(arr, j+1, high);
}

int main() {
  int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  sort(arr, 0, 9);

  for(int i=0; i<10; i++)
    cout << arr[i] << endl;
}
