// Octal to Decimal
// SlothyCoder16
// August 28, 2020

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int count = 0;
  int decimal = 0;
  while(n != 0) {
    int rem = n % 10;
    n = n / 10;
    count++;
    decimal = decimal + rem*pow(8, count-1);
  }

  cout << decimal << endl;
}
