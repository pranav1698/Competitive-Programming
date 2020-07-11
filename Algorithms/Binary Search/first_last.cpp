// Finding index of first and last instance of an element in an array
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

    int firstPosition(vector<int>& nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        while(max >= min) {
            int guess = min + (max - min) / 2;
            if(nums[guess] >= target) {
                max = guess - 1;
            } else if(nums[guess] < target) {
                min = guess + 1;
            }
        }

        return min;
    }

    int lastPosition(vector<int> nums, int target) {
        int min = 0;
        int max = nums.size() - 1;
        while(max >= min) {
            int guess = min + (max-min)/2;
            if(nums[guess] > target) {
                max = guess - 1;
            } else if(nums[guess] <= target) {
                min = guess + 1;
            }
        }

        return max;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res;
        int index1, index2;
        if(nums.size() == 0){
            res.push_back(-1);
            res.push_back(-1);
            return res;
        } else if(nums.size() == 1) {
            index1  = doSearch(nums, target);
            if(index1 == -1) {
                index2 = -1;
            } else {
                index1 = firstPosition(nums, target);
                res.push_back(index1);
                res.push_back(index1);
                return res;
            }
        } else {
            index1  = doSearch(nums, target);
            if(index1 == -1){
                index2 = -1;
            } else {
                index1 = firstPosition(nums, target);
                index2 = lastPosition(nums, target);
                cout << index2 << endl;
            }
        }

        res.push_back(index1);
        res.push_back(index2);
        return res;
    }
};
