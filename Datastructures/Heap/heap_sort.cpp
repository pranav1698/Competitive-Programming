// Implementation of in-place heap sort
// SlothyCoder16
// July 31, 2020

#include <bits/stdc++.h>
using namespace std;

void swap(int* H, int a, int b) {
  int temp = H[a];
  H[a] = H[b];
  H[b] = temp;
}


void shiftDown(int* H, int index, int last) {
  int maxIndex = index;
  int l = 2*index + 1;
  if(l <= last && H[l] > H[index])
    maxIndex = l;
  int r = 2*index + 2;
  if(r <= last && H[r] > H[maxIndex])
    maxIndex = r;

  if(maxIndex != index) {
    swap(H, index, maxIndex);
    shiftDown(H, maxIndex, last);
  }
}

void heapify(int* H, int size) {
  int last = size - 1;
  int index;
  if((last & 1) == 0) {
    index = (last/2) - 1;
  } else {
    index = last / 2;
  }

  while(index >= 0) {
    shiftDown(H, index, last);
    index = index -1;
  }
}

void printHeap(int* H, int n) {
  for(int i=0; i<n; i++) {
    cout << H[i] << endl;
  }
}

void heapifySort(int* H, int size) {
  int last = size-1;
  while(last > 0) {
    swap(H, 0, last);
    last = last - 1;
    shiftDown(H, 0, last);
  }
}


int main() {
  int arr[8] = {8, 3, 4, 6, 2, 5, 7, 9};
  heapify(arr, 8);

  printHeap(arr, 8);
  heapifySort(arr, 8);

  cout << "Sorted List: " << endl;
  printHeap(arr, 8);
}
