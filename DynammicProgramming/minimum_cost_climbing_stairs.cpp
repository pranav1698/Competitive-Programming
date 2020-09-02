// Find minimum cost climbing stairs
// SlothyCoder16
// September 01, 2020

class Solution {
public:
    // dp[i] = minimum cost required to reach that stair
    // dp[0] = 0 && dp[1] = 0 as we can start from both the stair 0 or 1
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size()+1, 0);
        dp[0]=0;
        dp[1]=0;
        for(int i=2; i<=cost.size(); i++){
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2]+cost[i-2]);
        }

        return dp[cost.size()];
    }
};
