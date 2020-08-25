// Finding size of maximum square matrices with all zeroes
// SlothyCoder16
// August 25, 2020

#include<bits/stdc++.h>
using namespace std;

int findMaxSquareWithAllZeros(int** arr, int row, int col){
    vector<vector<int>> dp(row, vector<int>(col, 0));

    for(int i=0; i<col; i++)
        if(arr[0][i] == 0)
            dp[0][i] = 1;

    for(int i=0; i<row; i++)
        if(arr[i][0] == 0)
            dp[i][0] = 1;

    for(int i=1; i<row; i++) {
        for(int j=1; j<col; j++) {
            if(arr[i][j] == 1) {
            	dp[i][j] = 0;
            } else {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
            }
        }
    }

    int max_size = INT_MIN;
    for(int i=0; i<row; i++)
        for(int j=0; j<col; j++)
            max_size = max(max_size, dp[i][j]);

    return max_size;

}
