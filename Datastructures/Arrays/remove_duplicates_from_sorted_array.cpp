// Remove Duplicates from sorted array
// SlothyCoder16
// September 226, 2020

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int curr=nums[0];
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == curr) {
                nums.erase(nums.begin()+i);
                i--;
            } else {
                curr=nums[i];
            }
        }

        return nums.size();
    }
};
