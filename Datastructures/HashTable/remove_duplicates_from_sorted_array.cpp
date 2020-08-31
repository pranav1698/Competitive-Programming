// Remove Duplicates from Sorted Array
// SlothyCoder16
// August 31, 2020

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        map<int, int> umap;
        for(int i=0; i<nums.size(); i++) {
            umap[nums[i]] += 1;
        }

        auto it = umap.begin();
        while(it != umap.end()) {
            while(it->second > 2) {
                it->second--;
                size--;
            }
            it++;
        }

        it = umap.begin();
        int count = 0;
        while(it != umap.end()) {
            while(it->second > 0) {
                nums[count] = it->first;
                it->second--;
                count++;
            }
            it++;
        }

        return size;
    }
};
