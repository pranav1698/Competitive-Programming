// Maximum Average Subarray 1
// SlothyCoder16
// September 17, 2020

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> sums(n);
        sums[0]=nums[0];
        for(int i=1; i<n; i++) sums[i] = sums[i-1]+nums[i];
        int sum = sums[k-1];
        for(int i=k; i<n; i++) sum=max(sum, sums[i]-sums[i-k]);

        return (double)sum/k;
    }
};
