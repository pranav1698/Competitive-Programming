// Implementation of heap operations
// SlothyCoder16
// July 31, 2020

#include <bits/stdc++.h>
using namespace std;

void swap(int* H, int a, int b) {
  int temp = H[a];
  H[a] = H[b];
  H[b] = temp;
}

// Parent element index for zero indexed array
int parent(int index) {
  if((index & 1) == 0) {
    return (index / 2) - 1;
  }

  return index / 2;
}

// Shifting element up if the child element is less than the parent element
void shiftUp(int* H, int index) {
  while(index > 0 && H[parent(index)] < H[index]) {
    swap(H, parent(index), index);
    index = parent(index);
  }
}

// Insert element to the heap tree
void insert(int* H, int* size, int maxSize, int p) {
  if(*size == maxSize)
    return;

  H[*size] = p;
  *size = *size + 1;
  shiftUp(H, *size - 1);
}

void print(int* H, int size) {
  for(int i=0; i<size; i++)
    cout << H[i] << endl;
}

// Get Maximum element in the max_heap
int getMax(int* H, int size) {
  if(size == 0)
    return -1;

  return H[0];
}

// Get Size of the max_heap
int getSize(int size) {
  return size;
}

// Check if heap is empty
bool is_heap_empty(int size) {
  if(size == 0)
    return true;

  return false;
}

// Getting left child of the parent
int leftChild(int index) {
  return (2*index) + 1;
}

// Getting right child of the parent
int rightChild(int index) {
  return (2*index) + 2;
}

// Shift Down the element
void shiftDown(int* H, int index, int size) {
  int maxIndex = index;
  int l = leftChild(index);
  if(l <= size && H[l] > H[maxIndex])
    maxIndex = l;

  int r = rightChild(index);
  if(r <= size && H[r] > H[maxIndex])
    maxIndex = r;

  if(maxIndex != index) {
    swap(H, index, maxIndex);
    shiftDown(H, maxIndex, size);
  }
}

// Extracting the maximum element from the Heap
int extractMax(int* H, int* size) {
  if(size == 0) return -1;

  int result = H[0];
  H[0] = H[*size - 1];
  *size = *size - 1;
  shiftDown(H, 0, *size);
  return result;
}

// Removing the element present in the given zero-indexed index
void remove(int* H, int index, int* size) {
  H[index] = INT_MAX;
  shiftUp(H, index);
  extractMax(H, size);
}

// Changing Priority for given zero-indexed index
void changePriority(int* H, int index, int priority, int size) {
  int oldPriority = H[index];
  H[index] = priority;
  if(priority > oldPriority) {
    shiftUp(H, index);
  } else {
    shiftDown(H, index, size);
  }
}

int main() {
  int size = 0;
  int maxSize = 13;
  int* H = new int[maxSize];

  insert(H, &size, maxSize, 42);
  insert(H, &size, maxSize, 29);
  insert(H, &size, maxSize, 18);
  insert(H, &size, maxSize, 14);
  insert(H, &size, maxSize, 7);
  insert(H, &size, maxSize, 18);
  insert(H, &size, maxSize, 12);
  insert(H, &size, maxSize, 11);
  insert(H, &size, maxSize, 13);
  insert(H, &size, maxSize, 54);

  print(H, size);

  cout << "The maximum element in the Heap is: " << " " << getMax(H, size) << endl;
  cout << "The size of the max heap is: " <<  " " << getSize(size) << endl;
  cout << is_heap_empty(size) << endl;
  cout << "Maximum element extracted: " << " " << extractMax(H, &size) << endl;
  cout << "Maximum element extracted: " << " " << extractMax(H, &size) << endl;
  remove(H, 3, &size);

  print(H, size);
  cout << " " << endl;
  changePriority(H, 3, 13, size);
  print(H, size);
}
