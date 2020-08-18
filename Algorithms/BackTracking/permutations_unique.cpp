// Finding unique permutations if array has duplicates
// SlothyCoder16
// August 18, 2020

class Solution {
public:
    set<vector<int>> s;

    void getPermutations(vector<int> nums, vector<int> &combos) {
        if(nums.size() == 0) {
            s.insert(combos);
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


    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> combos;
        getPermutations(nums, combos);

        set<vector<int>>::iterator it = s.begin();
        vector<int> temp = *it;
        vector<vector<int>> ans;

        while(it != s.end()) {
            ans.push_back(*it);
            it++;
        }
        return ans;
    }
};
