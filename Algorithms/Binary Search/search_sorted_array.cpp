// Returning tru or false for element in sorted array
// SlothyCoder16
// July 11, 2020

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        sort(nums.begin(), nums.end());

        while(max >= min) {
            int guess = min + (max-min) / 2;

            if(nums[guess] > target) {
                max = guess - 1;
            } else if(nums[guess] < target) {
                min = guess + 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
