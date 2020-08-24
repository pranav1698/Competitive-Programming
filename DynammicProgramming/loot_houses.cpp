// Loot houses if consecutive houses cannot be looted
// SlothyCoder16
// August 24, 2020

// dp[i]: Maximum amount of money that can be looted, upto index i
// for any i, we can either loot the house or not:
// Cases: 1) we have not looted any house, this is the first house we are looting
//        2) we have looted houses, we do not want to loot this house hence, this possiblity is dp[i-1] which will get maximum loot upto i-1
//        3) we have looted houses, we want to loot this house hence, we will have to add current money(arr[i]) to dp[i-2]

#include <bits/stdc++.h>
using namespace std;

int getMaxMoney(int arr[], int n){
    int dp[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i=2; i<n; i++) {
        dp[i] = max(max(arr[i], dp[i-1]), dp[i-2] + arr[i]);
    }

	return dp[n-1];
}
