// Finding Rectangle with Maximum sum using DP
// TLE Solution
// SlothyCoder16
// August 20, 2020;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int limit) {
        int res = INT_MIN;

        int dp[matrix.size()][matrix[0].size()];
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++) {
                if(matrix[i][j] <= limit) {
                    res = max(res, matrix[i][j]);
                }
                dp[i][j] = 0;
            }
        }

        for(int i=0; i<matrix.size(); i++) {
            for(int j=0; j<matrix[0].size(); j++) {
                for(int k=i; k<matrix.size(); k++) {
                    for(int l=j; l<matrix[0].size(); l++) {
                        dp[i][j] += matrix[k][l];
                    }
                }
            }
        }

        int area = 0;
        for(int i=0; i<matrix.size()-1; i++) {
            for(int j=0; j<matrix[0].size()-1; j++) {
                int k=i;
                while(k<matrix.size()) {
                    int l=j;
                    while(l < matrix[0].size()) {
                        area = dp[i][j];
                        if(l<(matrix[0].size() - 1)) {
                            area -= dp[i][l+1];
                        }
                        if(k<(matrix.size()-1)) {
                            area -= dp[k+1][j];
                        }
                        if(k<(matrix.size()-1) && l<(matrix[0].size() - 1)) {
                            area += dp[k+1][l+1];
                        }

                        if(area <= limit) {
                            res = max(res, area);
                        }
                        l++;
                    }
                    k++;

                }
            }
        }

        int m = matrix.size();
        int n = matrix[0].size();
        for(int i=0; i<m; i++) {
            if(dp[i][n-1] <= limit) {
                res = max(res, dp[i][n-1]);
            }
        }

        for(int j=0; j<n; j++) {
            if(dp[m-1][j] <= limit) {
                res = max(res, dp[m-1][j]);
            }
        }

        return res;
    }
};
