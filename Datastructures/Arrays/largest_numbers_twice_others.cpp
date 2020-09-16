// Largest Number that is twice the others
// SlothyCoder16
// September 18, 2020

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int max_num=INT_MIN;
        int max_index=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] > max_num){
                max_num=nums[i];
                max_index=i;
            }
        }

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]!=max_num) {
                if(2*nums[i] > max_num) return -1;
            }
        }

        return max_index;
    }
};
