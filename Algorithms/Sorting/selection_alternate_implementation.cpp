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

void sort(int* arr, int n) {
  for(int i=n-1; i>0; i--) {
    int max_index = i;
    int max_element = INT_MIN;
    for(int j=i; j>=0; j--) {
      if(arr[j] > max_element) {
        max_index = j;
        max_element = arr[j];
      }
    }
    swap(arr, i, max_index);
  }
}

int main() {
  int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  sort(arr, 10);

  for(int i=0; i<10; i++)
    cout << arr[i] << endl;
}
