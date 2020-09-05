// Best time to buy and sell stock with atmost k transactions
// SlothyCoder16
// September 05, 2020

class Solution {
public:
    int findProfit(vector<int> &prices, int n, int rem, int k, int isOngoing, vector<vector<vector<int>>> &dp) {
        if(rem == 0) return 0;
        if(dp[rem][k][isOngoing] > -1) return dp[rem][k][isOngoing];

        int option1 = findProfit(prices, n, rem-1, k, isOngoing, dp);
        int option2 = 0;
        if(isOngoing == 1) {
            option2 = prices[n-rem] + findProfit(prices, n, rem-1, k-1, 0, dp);
        } else {
            if(k>0) {
                option2 = -prices[n-rem] + findProfit(prices, n,rem-1, k, 1, dp);
            }
        }

        dp[rem][k][isOngoing] = max(option1, option2);
        return dp[rem][k][isOngoing];
    }

    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1, vector<vector<int>>(k+1, vector<int>(2, -1)));
        int ans = findProfit(prices, prices.size(), prices.size(), k, 0, dp);

        return ans;
    }
};
