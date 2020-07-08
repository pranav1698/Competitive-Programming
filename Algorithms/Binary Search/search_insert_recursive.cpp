// Recursive Solution to Search or Insert
// SlothyCoder16
// July 9, 2020


class Solution {
public:
    int doSearch(vector<int>& nums, int min, int max, int target) {
        if(max < min)
            return min;

        int guess = (min + max) / 2;

        if(nums[guess] > target) {
            return doSearch(nums, min, guess - 1, target);
        } else if(nums[guess] < target) {
            return doSearch(nums, guess + 1, max, target);
        }

        return guess;
    }



    int searchInsert(vector<int>& nums, int target) {
       return  doSearch(nums, 0, nums.size() - 1, target);
    }
};
