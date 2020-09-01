// Contains Duplicate with indice difference atmost k
// SlothyCoder16
// September 01, 2020

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        for(int i=0; i<nums.size(); i++) {
            if(umap[nums[i]] == 0) {
                umap[nums[i]] = i+1;
            } else {
                if((i - umap[nums[i]] + 1) <= k) {
                    return true;
                }
                umap[nums[i]] = max(umap[nums[i]], i+1);
            }
        }

        return false;
    }
};
