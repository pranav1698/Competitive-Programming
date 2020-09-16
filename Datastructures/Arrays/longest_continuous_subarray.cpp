// Finding the length of longest contnuous subarray
// SlothyCoder16
// September 17, 2020 

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n, 1);
        if(n==0) return 0;
        for(int i=1; i<n; i++) if(nums[i-1]<nums[i]) dp[i]=dp[i-1]+1;

        int max_length=INT_MIN;
        for(int i=0; i<n; i++) max_length = max(max_length, dp[i]);

        return max_length;
    }
};
