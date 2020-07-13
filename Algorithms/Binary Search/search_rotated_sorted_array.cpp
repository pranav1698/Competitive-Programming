// Modified Binary Search to get target in rotated sorted array
// SlothyCoder16
// July 13, 2020

class Solution {
public:
    int doSearch(vector<int> nums, int min, int max, int target) {
        while(max >= min) {
            int guess = min + (max - min) / 2;

            if(nums[guess] > target) {
                max = guess - 1;
            } else if(nums[guess] < target) {
                min = guess + 1;
            } else {
                return guess;
            }
        }

        return -1;
    }

    int findPivot(vector<int> nums) {
        int min = 0;
        int max = nums.size() - 1;

        while(max >= min) {
            if(nums[min] <= nums[max])
                return min;

            int guess = min + (max - min) / 2;
            int next = (guess + 1) % nums.size();
            int prev = (guess + (nums.size() - 1)) % nums.size();

            if(nums[guess] <= nums[next] && nums[guess] <= nums[prev])
                return guess;

            if(nums[guess] <= nums[max]) {
                max = guess - 1;
            } else if(nums[guess] >= nums[min]) {
                min = guess + 1;
            }
        }

        return -1;
    }

    int search(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return -1;
        }

        int pivot = findPivot(nums);

        int prev = (pivot + (nums.size() - 1)) % nums.size();

        int res;

        int left_res = doSearch(nums, 0, prev, target);
        int right_res = doSearch(nums, pivot, nums.size() - 1, target);

        if(left_res == -1 && right_res == -1)
            res = -1;

        if(left_res != -1)
            res = left_res;

        if(right_res != -1)
            res = right_res;

        return res;
    }
};
