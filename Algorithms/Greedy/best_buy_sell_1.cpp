// Find max profit buying and selling stock
// SlothyCoder16
// September 01, 2020

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0) return 0;

        int max_right = prices[n-1];
        int max_profit = 0;
        for(int i=n-2; i>=0; i--) {
            max_right = max(max_right, prices[i+1]);
            max_profit = max(max_profit, max_right - prices[i]);
        }

        return max_profit;
    }
};
