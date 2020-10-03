// Find k diff pairs in array
// SlothyCoder16
// October 03, 2020

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        unordered_map<int, bool> visited;
        for(int i=0; i<nums.size(); i++) {
            umap[nums[i]]+=1;
        }

        int count=0;
        for(int i=0; i<nums.size(); i++) {
            if(!visited[nums[i]]) {
                if(k==0 && umap[nums[i]]>=2) count++;
                else if(k!=0 && umap[nums[i]+k]>=1) count++;
                visited[nums[i]]=true;
            }
        }

        return count;
    }
};
