// Find count of number with even number of digits
// SlothyCoder16
// September 20, 2020

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count=0;

        for(int i=0; i<nums.size(); i++) {
            if((to_string(nums[i]).size()&1) == 0) count++;
        }

        return count;
    }
};
