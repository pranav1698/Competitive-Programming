// Minimum Perfect Squares for a given number
// SlothyCoder16
// September 01, 2020

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        if(n<1) return 0;
        dp[1] = 1;
        if(n<2) return 1;
        dp[2] = 2;
        if(n<3) return 2;
        dp[3] = 3;
        if(n<4) return 3;

        for(int i=4; i<=n; i++) {
            dp[i] = i;
            for(int j=0; j<=floor(sqrt(i)); j++) {
                dp[i] = min(dp[i], 1+dp[i-(j*j)]);
            }
        }

        return dp[n];
    }
};
