// Minimum steps to make two strings equal using LCS logic
// SlothyCoder16
// September 03, 2020

#include <bits/stdc++.h>
#include<iostream>
#include<cstring>
using namespace std;

int editDistance(string s1, string s2){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
	int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, 0));

    if(s1[0] != s2[0]) dp[0][0] = 1;
    for(int j=1; j<m; j++) {
    	if(s1[0] == s2[j]) {
           dp[0][j] = j;
        } else {
            dp[0][j] = dp[0][j-1] + 1;
        }
    }
    for(int i=1; i<n; i++) {
        if(s2[0] == s1[i]) {
            dp[i][0] = i;
        } else {
            dp[i][0] = dp[i-1][0] + 1;
        }
    }

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            if(s1[i] == s2[j]) {
                dp[i][j]  = dp[i-1][j-1];
            } else {
                dp[i][j] = min(min(dp[i-1][j-1] + 1, dp[i-1][j] + 1), dp[i][j-1] + 1);
            }
        }
    }

    return dp[n-1][m-1];
}
