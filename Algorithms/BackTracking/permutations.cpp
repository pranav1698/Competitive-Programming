// Given an array of integers, find total number of permutations
// SlothyCoder16
// August 18, 2020

class Solution {
public:
    vector<vector<int>> ans;

    void getPermutations(vector<int> nums, vector<int> &combos) {
        if(nums.size() == 0) {
            ans.push_back(combos);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            combos.push_back(nums[i]);
            vector<int> temp = nums;
            vector<int>::iterator it = temp.begin();
            temp.erase(it + i);
            getPermutations(temp, combos);
            combos.pop_back();
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> combos;
        getPermutations(nums, combos);

        return ans;
    }
};
