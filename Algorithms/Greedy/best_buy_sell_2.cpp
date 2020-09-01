// Best time to buy and sell stock any number of times
// SlothyCoder16
// September 01, 2020


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        for(int i = 1; i < prices.size(); i++){
          if(prices[i] > prices[i - 1])
            maxprofit += prices[i] - prices[ i - 1];
        }
      return maxprofit;
    }
};
