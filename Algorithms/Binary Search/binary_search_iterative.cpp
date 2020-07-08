// Iterative Solution to Binary Search
// SlothyCoder16
// July 8, 2020


#include <bits/stdc++.h>
using namespace std;

int main() {
  int arr[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

  int min=0;
  int max=24;
  int guess;
  while(max >= min) {
    guess = (min + max) / 2;
    if(arr[guess] > 73) {
      max = guess - 1;
    } else if(arr[guess] < 73 ) {
      min = guess + 1;
    } else {
      cout << guess + 1 << endl;
      return 0;
    }
  }

  cout << -1 << endl;
}
