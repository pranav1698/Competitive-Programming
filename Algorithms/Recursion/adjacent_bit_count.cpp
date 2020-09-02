// Adjacent Bit Count for bit string
// SlothyCoder16
// September 02, 2020

#include <bits/stdc++.h>
using namespace std;

// the first parameter is the value of first bit, for a bit of n size
// (5,2,1) means that the value of first bit in string of 5 size is 1

int countStrings(int n, int k, int first) {
  if(k < 0) return 0;
  if(n == 1) {
    if(k == 0) {
      return 1;
    } else {
      return 0;
    }
  }

  if(first == 1) return countStrings(n-1, k-1, 1) + countStrings(n-1,k,0);
  return countStrings(n-1, k, 0) + countStrings(n-1, k, 1);
}

int main() {
  int t;
  cin >> t;
  while(t--) {
    int n, k;
    cin >> n >> k;
    cout << countStrings(n, k, 1) + countStrings(n,k,0) << endl;
  }
}
