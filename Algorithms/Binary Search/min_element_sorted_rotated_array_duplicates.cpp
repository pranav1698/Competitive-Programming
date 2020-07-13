// Modified Binary Search to get minimum element in Sorted Rotated Array
// SlothyCoder16
// July 14, 2020


class Solution {
public:
    int findMin(vector<int>& nums) {
        int res;
        if(nums.size() == 0)
            return -1;

        int min = 0;
        int max = nums.size() - 1;

        while(max >= min) {
            int guess = min + (max - min) / 2;

            int next = (guess + 1) % nums.size();
            int prev = (guess + (nums.size() - 1)) % nums.size();

            if(nums[guess] <= nums[next] && nums[guess] <= nums[prev]){
                res = guess;
            }

            if(nums[guess] <= nums[max]) {
                max = max - 1;
            } else if(nums[guess] >= nums[min]) {
                min = min + 1;
            }
        }

        return  nums[res];
    }
};
