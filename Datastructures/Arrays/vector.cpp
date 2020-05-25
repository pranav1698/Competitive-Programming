// Implementation of vector functionalities
// SlothyCoder16
// May 23, 2020

#include <bits/stdc++.h>
using namespace std;

class vectorClass {
public:
    int* arr;
    int capacity=1;
    int size=0;
};


void create_vector(vectorClass v){
    int* temp = new int[2*v.capacity];
    int* ptr = &temp[0];
    for(int i=4; i<=10; i++){

    }

}


int main() {
    vectorClass v;
    create_vector(v);
}
