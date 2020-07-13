// Accepted solution for peak element bruteforce using (linear search)
// SlothyCoder16
// July 14, 2020

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1)
            return 0;

        for(int i=0; i<nums.size(); i++) {
            int next = (i + 1) % nums.size();
            int prev = (i + (nums.size() - 1))%nums.size();

            if(nums[i] > nums[next] && nums[i] > nums[prev])
                return i;
        }

        return 0;
    }
};
