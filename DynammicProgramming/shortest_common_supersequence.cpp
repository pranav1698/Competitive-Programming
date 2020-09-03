// Shortest Common Subsequence of two strings
// SlothyCoder16
// September 03, 2020

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<string>> dp(n, vector<string>(m, ""));
        if(str1[0] == str2[0]) dp[0][0] = str1[0];
        for(int j=1; j<m; j++) {
            if(str1[0] == str2[j]) dp[0][j] = str1[0];
            else dp[0][j] = dp[0][j-1];
        }

        for(int i=1; i<n; i++) {
            if(str1[i] == str2[0]) dp[i][0] = str2[0];
            else dp[i][0] = dp[i-1][0];
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++ ) {
                if(str1[i] == str2[j]) {
                    dp[i][j] = dp[i-1][j-1] + str1[i];
                } else {
                    if(dp[i-1][j].length() >= dp[i][j-1].length()) {
                        dp[i][j] = dp[i-1][j];
                    } else {
                        dp[i][j] = dp[i][j-1];
                    }
                }
            }
        }

        string lcs = dp[n-1][m-1];
        int i=0;
        int j=0;
        int k=0;

        string ans="";
        while(i<n && j<m && k<lcs.length()) {
            if(str1[i] == str2[j] && str1[i] == lcs[k]) {
                ans += lcs[k];
                i++;
                j++;
                k++;
            } else {
                if(str1[i] == lcs[k]) {
                    ans += str2[j];
                    j++;
                } else {
                    ans += str1[i];
                    i++;
                }
            }
        }

        while(i<n) ans+=str1[i++];
        while(j<m) ans+=str2[j++];
        return ans;
    }
};
