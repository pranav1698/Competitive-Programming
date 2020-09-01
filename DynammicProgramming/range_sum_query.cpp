// Range Sum Query for given array
// SlothyCoder16
// September 01, 2020

class NumArray {
public:
    vector<int> dp;
    NumArray(vector<int>& nums) {
        this->dp = vector<int>(nums.size(), 0);
        if(nums.size() != 0) {
            this->dp[0] = nums[0];
            for(int i=1; i<nums.size(); i++) this->dp[i] = this->dp[i-1] + nums[i];
        }
    }

    int sumRange(int i, int j) {
        if(this->dp.size() == 0) return 0;
        if(i == 0) return this->dp[j];

        return this->dp[j] - this->dp[i-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
