// Jumping in an array using pointers
// SlothyCoder16
// May 23, 2020
#include <bits/stdc++.h>
using namespace std;

int main() {
    int a[] = {1,2,3,4,5,6};
    int* ptr = &a[0];
    int i=0;
    while(i < 6){
        cout << *ptr << endl;
        i++;
        ptr++;
    }
}
