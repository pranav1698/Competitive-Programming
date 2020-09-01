// Contains Duplicate in the Array
// SlothyCoder16
// September 01, 2020

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;

        for(int i=0; i<nums.size(); i++) {
            if(umap[nums[i]] == 0) {
                umap[nums[i]] += 1;
            } else {
                return true;
            }
        }

        return false;
    }
};
