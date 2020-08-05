// Implementation of bubble sort in C
// SlothyCoder16
// August 05, 2020

#include <bits/stdc++.h>
using namespace std;

void swap(int* arr, int i, int j) {
  int temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}

// The smallest element at each iteration will be at the start of the range
void sort(int* arr, int n) {
  for(int i=0; i<n-1; i++) {
    for(int j=n-1; j>i; j--) {
      if(arr[j] < arr[j-1]) {
        swap(arr, j, j-1);
      }
    }
  }
}

int main() {
  int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  sort(arr, 10);

  for(int i=0; i<10; i++)
    cout << arr[i] << endl;
}
