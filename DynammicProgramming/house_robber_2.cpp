// Robbing houses in a circular colony, no two consecutive houses can be looted
// SlothyCoder16
// August 25, 2020

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        int dp1[nums.size()], dp2[nums.size()];

        if(nums.size()==2)
            return max(nums[0],nums[1]);;
        dp1[0]=nums[0];
        dp1[1]=max(nums[0],nums[1]);

        dp2[1]=nums[1];
        dp2[2]=max(nums[1],nums[2]);


        for(int i=2;i<nums.size()-1;i++){
            dp1[i] = max(dp1[i-2]+nums[i],dp1[i-1]);
        }
        for(int i=3;i<nums.size();i++){
            dp2[i] = max(dp2[i-2]+nums[i],dp2[i-1]);
        }

        return max(dp1[nums.size() - 2], dp2[nums.size()-1]);
    }
};
