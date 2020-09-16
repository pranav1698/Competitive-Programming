// Maximum product of three numbers
// SlothyCoder16
// September 17, 2020

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left=0;
        int right=nums.size()-1;
        if(nums.size()<3) return 0;

        int leftProduct=nums[left]*nums[left+1]*nums[right];
        int rightProduct=nums[right]*nums[right-1]*nums[right-2];

        return max(leftProduct, rightProduct);
    }
};
