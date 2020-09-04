// 0-1 Knapsack Problem
// SlothyCoder16
// September 04, 2020

#include <bits/stdc++.h>
using namespace std;

// int knapsack(int* weights, int* values, int n, int maxWeight){
//
//   /* Don't write main().
//    *  Don't read input, it is passed as function argument.
//    *  Return output and don't print it.
//    *  Taking input and printing output is handled automatically.
//   */
//   if(n == 0)
//     return 0;
//   if(maxWeight <= 0)
//     return 0;
//
//     if(weights[n-1] <= maxWeight){
//       int option1 = values[n-1] + knapsack(weights, values, n-1, maxWeight-weights[n-1]);
//       int option2 = knapsack(weights, values, n-1, maxWeight);
//
//       return max(option1, option2);
//     } else {
//       return knapsack(weights, values, n-1, maxWeight);
//     }
//
// }

int knapsack(int* B, int* A, int n, int C){
    vector<vector<int>> dp(2, vector<int>(C+1, 0));

    int flag=0;
    for(int i=0; i<n; i++) {
        for(int j=1; j<=C; j++) {
            if(j>=B[i]) {
                dp[flag][j] = max(dp[flag^1][j], dp[flag^1][j-B[i]]+A[i]);
            } else {
                dp[flag][j] = dp[flag^1][j];
            }
        }
        flag = flag^1;
    }

    return dp[flag^1][C];
}
