// Making a pascal triangle
// SlothyCoder16
// August 31, 2020

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(numRows, vector<int>());
        for(int i=0; i<numRows; i++) {
            res[i] = vector<int>(i+1, 0);
            if(i==0) {
              res[i][0] = 1;
            } else if(i == 1){
                res[i][0] = 1;
                res[i][1] = 1;
            } else {
                res[i][0] = 1;
                res[i][i] = 1;
                for(int j=1; j<i; j++) res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }

        return res;
    }
};
