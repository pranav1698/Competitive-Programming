// Decimal to Octal
// SlothyCoder16
// August 28, 2020
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int count =0;
  int octal = 0;
  while(n != 0) {
    int rem = n % 8;
    n = n / 8;
    count++;
    octal = octal + rem*(pow(10, count-1));
  }

  cout << octal << endl;
}
