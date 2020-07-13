// Longest Increasing Subsequence using DP
// SlothyCoder16
// July 14, 2020

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];

        if(nums.size() == 0)
            return 0;

        dp[0] = 1;
        for(int i=1; i<nums.size(); i++) {
            dp[i] = 1;
            for(int j=0; j<i; j++) {
                if(nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }
        int res = INT_MIN;

        for(int i=0; i<nums.size(); i++)
            res = max(res, dp[i]);
        return res;
    }
};
