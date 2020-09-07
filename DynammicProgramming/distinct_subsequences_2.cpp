// FInding distinct subsequences that are equivalent to another sequence
// SlothyCoder16
// September 07, 2020

class Solution {
public:
    int mod = 1e9+7;
    typedef unsigned long long int ll;
    int numDistinct(string s, string t) {
        int n=s.length();
        int m=t.length();
        if(n == 0 && m==0) return 1;
        if(n==0) return 0;
        if(m==0) return 1;
        vector<vector<ll>> dp(n, vector<ll>(m, 0));
        if(s[0] == t[0]) dp[0][0] = 1;

        for(int i=1; i<n; i++) {
            if(s[i] == t[0]) dp[i][0] = dp[i-1][0]+1;
            else dp[i][0] = dp[i-1][0];
        }

        for(int i=1; i<n; i++) {
            for(int j=1; j<m; j++) {
                if(i<j) dp[i][j]=0;
                if(s[i] == t[j]) {
                    dp[i][j] = ((dp[i-1][j]%mod) + (dp[i-1][j-1]%mod)%mod);
                } else {
                    dp[i][j] = dp[i-1][j];
                }
                cout << dp[i][j] << endl;
            }
        }


        return dp[n-1][m-1];
    }
};
