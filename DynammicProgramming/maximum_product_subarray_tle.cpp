// Maximum Product Subarray
// SlothyCoder16
// September 02, 2020

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()-1, vector<int>(nums.size(), 0));
        int max_product = nums[0];
        if(nums.size() == 1) return max_product;
        dp[0][0] = nums[0];
        for(int j=1; j<nums.size(); j++) {
            max_product = max(max_product, nums[j]);
            dp[0][j] = dp[0][j-1] * nums[j];
            max_product = max(max_product, dp[0][j]);
        }

        for(int i=1; i<nums.size()-1; i++) {
            dp[i][i] = nums[i];
            for(int j=i+1; j<nums.size(); j++) {
                dp[i][j] = dp[i][j-1] * nums[j];
                max_product = max(max_product, dp[i][j]);
            }
        }

        return max_product;
    }
};
