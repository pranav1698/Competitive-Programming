// Minimum coin change pattern for coin change problem
// SlothyCoder16
// August 24, 2020

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int dp[coins.size() + 1][amount+1];
        dp[0][0] = 1;
        for(int j=1; j<=amount; j++) dp[0][j] = INT_MAX;
        for(int i=1; i<=coins.size(); i++) dp[i][0] = 0;

        for(int i=1; i<=coins.size(); i++) {
            for(int j=1; j<=amount; j++) {
                dp[i][j] = dp[i-1][j];
                if(j >= coins[i-1]) {
                    if(dp[i][j-coins[i-1]] != INT_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i][j-coins[i-1]] + 1);
                    }
                }
            }
        }

        if(dp[coins.size()][amount] != INT_MAX) return dp[coins.size()][amount];

        return -1;
    }
};
