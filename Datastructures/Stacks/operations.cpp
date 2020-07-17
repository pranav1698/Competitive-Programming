// Implementation of stack using array and subsequent operations
// SlothyCoder16
// July 13, 2020


#include <bits/stdc++.h>
using namespace std;

// Top in stack
int top(int* stack, int numElements) {
  return stack[numElements-1];
}

// Pop in stack
int pop(int* stack, int* numElements) {
  int res = stack[*numElements - 1];
  stack[*numElements-1] = 0;
  *numElements = *numElements - 1;
  return res;
}

// Push elements in stack
int push(int* stack, int numElements, int val) {
  stack[numElements] = val;
  numElements = numElements + 1;
  return numElements;
}

// Print elements in stack
void print(int* stack, int numElements) {
  for(int i=0; i < numElements; i++) {
    cout << stack[i] << endl;
  }
}

// Is Stack Empty??
bool empty() {
  if(numElements == 0) {
    return true;
  }

  return false;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int numElements=0;
  int stack[0];

  for(int i=0; i<5; i++) {
    numElements = push(stack, numElements, arr[i]);
    // stack[numElements] = arr[i];
    // numElements = numElements + 1;
  }

  numElements = push(stack, numElements, 6);
  print(stack, numElements);

  int topmostElement = top(stack, numElements);
  cout << "Topmost Element: " << topmostElement << endl;

  numElements = push(stack, numElements, 8);
  int popResult = pop(stack, &numElements);
  cout << "Result of POP " << popResult << endl;

  numElements = push(stack, numElements, 7);
  print(stack, numElements);
}
