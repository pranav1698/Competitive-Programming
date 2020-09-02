// Find minimum number of chocolates that needs to be given
// SlothyCoder16
// September 02, 2020

#include <bits/stdc++.h>
using namespace std;

int getMin(int *arr, int n){
   /* Don't write main().
      Don't read input, it is passed as function argument.
      Return output and don't print it.
      Taking input and printing output is handled automatically.
   */
	vector<int> dp(n, 1);
    dp[0]=1;

    for(int i=1; i<n; i++) {
        if(arr[i] > arr[i-1]) dp[i] = dp[i-1] + 1;
        if(arr[i] < arr[i-1]) {
            for(int j=i; j>=1; j--) {
                if(dp[j] == dp[j-1]) dp[j-1] = dp[j] + 1;
                else break;
            }
        }
    }

    unsigned long long int sum = 0;
    for(int i=0; i<n; i++) sum += dp[i];

    return sum;
}
