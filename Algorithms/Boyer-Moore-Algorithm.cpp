// Boyer Moore Algorithm to find majority element in an array
// SlothyCoder16
// July 11, 2020


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority = 0;

        for(int i=0; i<nums.size(); i++){
            if(count == 0)
                majority = nums[i];

            if(nums[i] == majority) {
                count += 1;
            } else {
                count += -1;
            }
        }

        return majority;
    }
};
