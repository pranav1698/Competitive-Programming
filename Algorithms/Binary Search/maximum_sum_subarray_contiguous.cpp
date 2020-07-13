// Maximum Sub Array Contiguous Bruteforce Accepted
// SlothyCoder16
// July 14, 2020

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        int total = INT_MAX;
        for(int i=0; i<nums.size(); i++) {
            int sum = 0;
            for(int j=i; j<nums.size(); j++) {
                sum += nums[j];
                if(sum >= s) {
                    total = min(total, j-i+1);
                    break;
                }
            }

        }

        if (total == INT_MAX)
            return 0;
        return total;
    }
};
