// Finding combinations in array for the sum using backtracking (with duplicate)
// SlothyCoder16
// August 18, 2020

class Solution {
public:
    set<vector<int>> s;

    void getCombinations(vector<int> &candidates, vector<int> &combos, int n, int target) {
        if(target == 0) {
            s.insert(combos);
            return;
        }
        if(n == 0 || candidates[candidates.size() - n] > target) {
            return;
        }

        getCombinations(candidates, combos, n-1, target);
        combos.push_back(candidates[candidates.size() - n]);
        getCombinations(candidates, combos, n-1, target-candidates[candidates.size() - n]);
        combos.pop_back();

    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> combos;
        getCombinations(candidates, combos, candidates.size(), target);

        vector<vector<int>> ans;
        set<vector<int>>::iterator it = s.begin();
        while(it != s.end()) {
            ans.push_back(*it);
            it++;
        }

        return ans;
    }
};
