// Partitioning a string for Quick Sort
// SlothyCoder16
// August 05, 2020

#include <bits/stdc++.h>
using namespace std;

string swap(string a, int i, int j) {
  char temp = a[i];
  a[i] = a[j];
  a[j] = temp;

  return a;
}

string partitionString(string a) {
  int lo = 0;
  int i = 1;
  int j = a.length() - 1;

  while(true) {
    while(a[i] < a[lo]) {
      i++;
    }

    while(a[j] > a[lo]) {
      j--;
    }

    if(i>=j) break;

    a = swap(a, i, j);
  }

  a = swap(a, lo, j);

  return a;
}

int main() {
  string a = "KRATELEPUIMQCXOS";
  a = partitionString(a);

  cout << a << endl;
}
