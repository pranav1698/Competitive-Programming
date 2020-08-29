// Maximum Contiguous Subarray Sum
// SlothyCoder16
// August 30, 2020

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int count = 0;
        int best = INT_MIN;
        int ret = INT_MIN;

        for(int i=0; i<nums.size(); i++) {
            count += nums[i];

            if(count < 0) count = 0;
            best = max(best, count);
            ret = max(ret, nums[i]);
        }

        if(ret<0) return ret;
        return best;
    }
};
