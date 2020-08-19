// Combinations sum given n and k
// SlothyCoder16
// August 19, 2020

class Solution {
public:
    vector<vector<int>> ans;
    void getCombinations(vector<int> &combos, int num, int n, int k, int target) {
        if(k == 0 && target == 0) {
            ans.push_back(combos);
            return;
        } else if(target <= 0) {
            return;
        } else if(k == 0) {
            return;
        } else if(n == 0) {
            return;
        }

        getCombinations(combos, num, n-1, k, target);
        combos.push_back(num - n + 1);
        getCombinations(combos, num, n-1, k-1, target-(num - n + 1));
        combos.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> combos;
        getCombinations(combos, 9, 9, k, n);

        return ans;
    }
};
