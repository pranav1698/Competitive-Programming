// Minimum product subarray math intuition
// SlothyCoder16
// September 02, 2020

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int min_curr = nums[0];
        int max_curr = nums[0];
        int res = nums[0];

        if(nums.size() == 0) return -1;

        for(int i=1; i<nums.size(); i++) {
            int c1 = max_curr * nums[i];
            int c2 = min_curr * nums[i];
            min_curr = min(nums[i], min(c1, c2));
            max_curr = max(nums[i], max(c1, c2));
            res = max(res, max_curr);
        }

        return res;
    }
};
