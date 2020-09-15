// Reshape the matrix
// SlothyCoder16
// September 17, 2020

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int m=nums.size();
        int n=nums[0].size();
        if(m*n != r*c) return nums;
        vector<int> temp;
        for(int i=0; i<m; i++)
            for(int j=0; j<n; j++)
                temp.push_back(nums[i][j]);

        vector<vector<int>> res(r);
        int k=0;
        for(int i=0; i<r; i++){
            res[i] = vector<int>(c);
            for(int j=0; j<c; j++) {
                res[i][j] = temp[k++];
            }
        }

        return res;
    }
};
