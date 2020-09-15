// Rotate array
// SlothyCoder16
// September 16, 2020

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k>n) k=k-n;
        string res="";
        for(int i=0; i<n; i++) res += to_string(nums[i]);
        res = res.substr(n-k) + res.substr(0, n-k);
        for(int i=0; i<n; i++) nums[i] = res[i]-'0';
    }
};
