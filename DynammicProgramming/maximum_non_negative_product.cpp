// Maximum Non Negative Product
// SlothyCoder16
// September 27, 2020

class Solution {
public:
    int mod=1e9+7;
    int maxProductPath(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>> minDp(m, vector<long long>(n, LONG_MAX));
        vector<vector<long long>> maxDp(m, vector<long long>(n, LONG_MIN));

        minDp[0][0]=grid[0][0];
        maxDp[0][0]=grid[0][0];
        for(int i=1; i<m; i++) {
            minDp[i][0] = min(((minDp[i-1][0]%mod)*(grid[i][0]%mod)%mod), ((maxDp[i-1][0]%mod)*(grid[i][0]%mod)%mod));
            maxDp[i][0] = max(((minDp[i-1][0]%mod)*(grid[i][0]%mod)%mod), ((maxDp[i-1][0]%mod)*(grid[i][0]%mod)%mod));
        }

        for(int j=1; j<n; j++) {
            minDp[0][j] = min(((minDp[0][j-1]%mod)*(grid[0][j]%mod)%mod), ((maxDp[0][j-1]%mod)*(grid[0][j]%mod)%mod));
            maxDp[0][j] = max(((minDp[0][j-1]%mod)*(grid[0][j]%mod)%mod), ((maxDp[0][j-1]%mod)*(grid[0][j]%mod)%mod));
        }

        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                maxDp[i][j] = max(max(((maxDp[i-1][j]%mod)*(grid[i][j]%mod))%mod, ((maxDp[i][j-1]%mod)*(grid[i][j]%mod))%mod), max((minDp[i-1][j]%mod)*(grid[i][j]%mod)%mod, ((minDp[i][j-1]%mod)*(grid[i][j]%mod))%mod));
                minDp[i][j] = min(min(((maxDp[i-1][j]%mod)*(grid[i][j]%mod))%mod, ((maxDp[i][j-1]%mod)*(grid[i][j]%mod))%mod), min((minDp[i-1][j]%mod)*(grid[i][j]%mod)%mod, ((minDp[i][j-1]%mod)*(grid[i][j]%mod))%mod));
            }
        }

        if(maxDp[m-1][n-1] < 0) return -1;
        return maxDp[m-1][n-1];
    }
};
