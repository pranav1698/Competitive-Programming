// Buy and sell stock
// SlothyCoder16
// September 01, 2020

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;

        vector<int> dp(prices.size(), 0);
        dp[n-1]=prices[n-1];
        for(int i=n-2; i>=0; i--) {
            dp[i] = max(dp[i+1], prices[i+1]);
        }

        int max_profit = INT_MIN;
        for(int i=0; i<prices.size(); i++) max_profit = max(max_profit, dp[i]-prices[i]);

        return max_profit;
    }
  };
