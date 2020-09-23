// Finding maximum gap between consecutive elements in a sorted array
// SlothyCoder16
// September 23, 2020

// O(NlogN) time and O(N) space
int Solution::maximumGap(const vector<int> &A) {
    vector<int> nums=A;
    if(nums.size() < 2) return 0;

    sort(nums.begin(), nums.end());
    int ans = INT_MIN;

    for(int i=1; i<nums.size(); i++)
        ans = max(ans, (nums[i] - nums[i-1]));

    return ans;
}
