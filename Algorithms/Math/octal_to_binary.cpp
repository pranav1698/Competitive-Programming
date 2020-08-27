// Converting octal to binary
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
    int rem = n%10;
    n = n/10;
    count++;
    decimal = decimal + rem*pow(8, count-1);
  }

  cout << decimal << endl;
  count = 0;
  int binary = 0;
  while(decimal != 0) {
    int rem = decimal % 2;
    decimal = decimal / 2;
    count++;
    binary = binary + rem*pow(10, count - 1);
  }

  cout << binary << endl;
}
