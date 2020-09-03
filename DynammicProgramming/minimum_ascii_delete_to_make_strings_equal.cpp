// Minimum ascii delete to make two strings equal?
// SlothyCoder16
// September 03, 2020


class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        if(s1[0] != s2[0]) dp[0][0] = (int)s1[0] + (int)s2[0];

        for(int j=1; j<m; j++) {
            if(s1[0] == s2[j]) {
                for(int k=0; k<j; k++) dp[0][j] += (int)s2[k];
            } else {
                dp[0][j] = dp[0][j-1] + (int)s2[j];
            }
        }

        for(int i=1; i<n; i++) {
            if(s1[i] == s2[0]) {
                for(int k=0; k<i; k++) dp[i][0] += (int)s1[k];
            } else {
                dp[i][0] = dp[i-1][0] + (int)s1[i];
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(s1[i] == s2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j] + (int)s1[i], dp[i][j-1] + (int)s2[j]);
                }
            }
        }

        return dp[n-1][m-1];
    }
};
