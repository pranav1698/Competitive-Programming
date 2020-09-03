// Delete opeation to make strings equal
// SlothyCoder16
// September 03, 2020

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n == 0 && m==0) return 0;
        if(n == 0) return m;
        if(m == 0) return n;
        vector<vector<int>> dp(n, vector<int>(m, 0));

        if(word1[0] != word2[0]) dp[0][0] = 2;
        for(int j=1; j<m; j++) {
            if(word1[0] == word2[j]) {
                dp[0][j] = j;
            } else {
                dp[0][j] = dp[0][j-1] + 1;
            }
        }

        for(int i=1; i<n; i++) {
            if(word1[i] == word2[0]) {
                dp[i][0] = i;
            } else {
                dp[i][0] = dp[i-1][0] + 1;
            }
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(word1[i] == word2[j]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                }
            }
        }

        return dp[n-1][m-1];
    }
};
