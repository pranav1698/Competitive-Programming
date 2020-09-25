// Move zeroes to the end of array
// SlothyCoder16
// September 26, 2020


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i=0;
        while(i<nums.size() && nums[i]!=0) i++;
        int j=i;
        while(j<nums.size() && nums[j]==0) j++;

        while(i<nums.size() && j<nums.size()) {
            if(nums[i]==0 && nums[j]!=0) {
                swap(nums[i], nums[j]);
                i++;
                j++;
            } else if(nums[j]==0) {
                j++;
            } else if(nums[i]!=0) {
                i++;
            }
        }
    }
};
