// Find if s is subsequence of t
// SlothyCoder16
// September 01, 2020

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<bool>> dp(2, vector<bool>(t.size(), false));
        if(s == "") return true;
        if(t == "") return false;
        if(s[0] == t[0]) dp[0][0] = true;

        for(int j=1; j<t.size(); j++) {
            if(s[0] == t[j]) dp[0][j] = true;
            else dp[0][j] = dp[0][j-1];
        }

        int flag = 1;
        for(int i=1; i<s.size(); i++) {
            for(int j=1; j<t.size(); j++) {
                if(s[i] == t[j]) {
                    dp[flag][j] = dp[flag^1][j-1];
                } else {
                    dp[flag][j] = dp[flag][j-1];
                }
            }
            flag = flag^1;
        }

        return dp[flag^1][t.size()-1];
    }
};
