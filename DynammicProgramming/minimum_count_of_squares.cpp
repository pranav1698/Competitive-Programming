// Find minimum count of sum of squares required
// SlothyCoder16
// August 26, 2020

#include<bits/stdc++.h>
using namespace std;


int minCount(int n){
      int* output= new int[n+1];

      output[0]=0;
      output[1]=1;
      output[2]=2;
      output[3]=3;

      for(int i=4; i<=n; i++){
        output[i]=i;
        for(int j=1; j<=ceil(sqrt(i)); j++){
          int temp = j*j;
          if(temp > i)
            break;
          else
            output[i] = min(output[i], 1+output[i-temp]);
        }
      }

      return output[n];
}
