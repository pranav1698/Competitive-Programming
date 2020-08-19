// Finding total combinations can be found using n and k
// SlothyCoder16
// August 19, 2020

class Solution {
public:
    vector<vector<int>> ans;

    void getCombinations(vector<int> &combos, int num, int n, int k) {
        if(k == 0) {
            ans.push_back(combos);
            return;
        }

        if(n == 0) {
            return;
        }

        getCombinations(combos, num, n-1, k);
        combos.push_back((num-n) + 1);
        getCombinations(combos, num, n-1, k-1);
        combos.pop_back();
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> combos;
        getCombinations(combos, n, n, k);

        return ans;
    }
};
