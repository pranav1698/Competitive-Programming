// Recursive Solution to Binary Search
// SlothyCoder16
// July 8, 2020

#include <bits/stdc++.h>
using namespace std;

int doSearch(int arr[], int min, int max, int target) {
  if (max < min)
    return -1;

  int guess = (min + max) / 2;
  if(arr[guess] < target) {
    return doSearch(arr, guess + 1, max, target);
  } else if(arr[guess] > target) {
    return doSearch(arr, min, guess - 1, target);
  }

  return guess + 1;
}

int main() {
  int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  int min = 0;
  int max = 24;
  cout << doSearch(arr, min, max, 73) << endl;
}
