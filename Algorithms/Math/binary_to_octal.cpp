// Converting binary to octal
// SlothyCoder16
// August 28, 2020

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int count =0;
  int decimal =0;

  while(n!=0) {
    int rem = n % 10;
    n = n / 10;
    count++;
    decimal += rem*pow(2, count-1);
  }

  cout << decimal << endl;
  count = 0;
  int octal = 0;
  while(decimal != 0) {
    int rem = decimal % 8;
    decimal = decimal / 8;
    count++;
    octal += rem*pow(10, count-1);
  }

  cout << octal << endl;
}
