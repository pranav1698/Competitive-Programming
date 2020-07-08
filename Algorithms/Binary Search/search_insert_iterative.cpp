// Iterative Solution to Search or Insert
// SlothyCoder16
// July 9, 2020


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
       int min = 0;
        int max = nums.size() - 1;
        int guess;
        while(max >= min) {
            guess = (min + max) / 2;
            if(nums[guess] > target) {
                max = guess - 1;
            } else if(nums[guess] < target) {
                min = guess + 1;
            } else {
                return guess;
            }
        }
        return min;
    }
};
