// Consecutive appearances of an element in a sorted arrat using binary search
// SlothyCoder16
// July 11, 2020

class Solution {
public:
    int doSearch(vector<int> nums, int target) {
        int min = 0;
        int max = nums.size() - 1;

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

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        if(nums.size() == 0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        } else if(nums.size() == 1) {
            int index1 = doSearch(nums, target);
            res.push_back(index1);
            res.push_back(index1);
            return res;
        } else {
            int index1 = doSearch(nums, target);
            int index2;
            if(index1 == -1) {
                index2 = -1;
            } else if (index1 == nums.size() - 1) {
                if(nums[index1 - 1] == target) {
                    index2 = index1 - 1;
                } else {
                    index2 = index1;
                }
            } else if (index1 == 0) {
                if(nums[index1 + 1] == target){
                    index2 = index1 + 1;
                } else {
                     index2 = index1;
                }
            } else {
                if(nums[index1 - 1] == target) {
                    index2 = index1 - 1;
                } else if (nums[index1 + 1] == target) {
                    index2 = index1 + 1;
                } else {
                    index2 = index1;
                }
            }

            res.push_back(index1);
            res.push_back(index2);
            sort(res.begin(), res.end());
        }

        return res;
    }
};
