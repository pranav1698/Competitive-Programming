// Finding all subsets for a given array 
// SlothyCoder16
// August 19, 2020

class Solution {
public:
    vector<vector<int>> ans;

    void getCombinations(vector<int> &nums, vector<int> &combos, int num, int n) {
        if(n == 0) {
            ans.push_back(combos);
            return;
        }

        getCombinations(nums, combos, num, n-1);
        combos.push_back(nums[num-n]);
        getCombinations(nums, combos, num, n-1);
        combos.pop_back();
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> combos;
        getCombinations(nums, combos, nums.size(), nums.size());

        return ans;
    }
};
