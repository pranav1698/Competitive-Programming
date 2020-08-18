// Finding combinations in array for the sum using backtracking (all unique)
// SlothyCoder16
// August 18, 2020

class Solution {
public:
    vector<vector<int>> ans;
    void getCombinations(vector<int> &candidates, vector<int> &combos, int n, int target) {
        if(target == 0) {
            ans.push_back(combos);
            return;
        }
        if(n == 0 || candidates[candidates.size() - n] > target) {
            return;
        }

        getCombinations(candidates, combos, n-1, target);
        combos.push_back(candidates[candidates.size() - n]);
        getCombinations(candidates, combos, n, target-candidates[candidates.size() - n]);
        combos.pop_back();

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combos;
        getCombinations(candidates, combos, candidates.size(), target);


        return ans;
    }
};
