// Find all numbers disappeared in array
// SlothyCoder16
// September 16, 2020

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<bool> visited(n+1, false);
        for(int i=0; i<nums.size(); i++) visited[nums[i]] = true;
        vector<int> res;
        for(int i=1; i<=n; i++) if(!visited[i]) res.push_back(i);
        return res;
    }
};
