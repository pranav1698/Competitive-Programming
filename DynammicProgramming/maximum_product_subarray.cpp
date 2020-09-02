// Maximum product subarray using min and max dp
// SlothyCoder16
// September 02, 2020

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        if(n == 0) return -1;
        vector<int> min_dp(n,0);
        vector<int> max_dp(n,0);

        min_dp[0] = nums[0];
        max_dp[0] = nums[0];

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] < 0) {
                max_dp[i] = max(nums[i], nums[i]*min_dp[i-1]);
                min_dp[i] = min(nums[i], nums[i]*max_dp[i-1]);
            } else {
                max_dp[i] = max(nums[i], nums[i]*max_dp[i-1]);
                min_dp[i] = min(nums[i], nums[i]*min_dp[i-1]);
            }
        }

        int ans=INT_MIN;
        for(int i=0; i<nums.size(); i++) ans = max(ans, max_dp[i]);

        return ans;
    }
};
