// Subarrays sum equals to k
// SlothyCoder16
// September 17, 2020

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       int count=0;
        int sum=0;
        map<int, int> umap;
        umap[0]=1;

        for(int i=0; i<nums.size(); i++) {
            sum+=nums[i];
            count+=umap[sum-k];
            umap[sum]+=1;
        }

        return count;
    }
};
