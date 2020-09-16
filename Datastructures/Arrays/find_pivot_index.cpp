// Finding pivot index in an array
// SlothyCoder16
// September 18, 2020

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int> forw(n,0);
        vector<int> back(n,0);
        if(n==0) return -1;
        if(n==1) return 0;

        forw[0]=nums[0];
        for(int i=1; i<n; i++) forw[i] = forw[i-1] + nums[i];
        back[n-1]=nums[n-1];
        for(int i=n-2; i>=0; i--) back[i] = back[i+1] + nums[i];

        if(back[1]==0) return 0;
        for(int i=1; i<n-1; i++) if(forw[i-1]==back[i+1]) return i;
        if(forw[n-2]==0) return n-1;


        return -1;
    }
};
