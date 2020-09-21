// Kth row of pascal triangle using O(k) space
// SlothyCoder16
// September 21, 2020

vector<int> Solution::getRow(int A) {
    vector<vector<int>> dp(2, vector<int>(A+1, 0));
    if(A==0) return {1};
    dp[0][0]=1;
    dp[0][1]=1;

    int flag=1;
    for(int i=2; i<=A; i++){
        dp[flag][0]=1;
        dp[flag][i]=1;
        for(int j=1; j<=i-1; j++) dp[flag][j] = dp[flag^1][j] + dp[flag^1][j-1];
        flag=flag^1;
    }

    return dp[flag^1];
}
