// Distinct Subsequences of a given string
// SlothyCoder16
// September 05, 2020

class Solution {
public:
    int mod = 1000000007;
    int distinctSubseqII(string str) {
        vector<int> dp(str.length(), 0);
        unordered_map<char, int> umap;
        dp[0] = 1;
        umap[str[0]] = 1;

        for(int i=1; i<str.length(); i++) {
            if(umap[str[i]] == 0) dp[i] = 1;
            bool flag = false;
            for(int j=0; j<i; j++) {
                if(umap[str[i]]-1 <= j) {
                    dp[i] = (dp[i]%mod + dp[j]%mod)%mod;
                    flag = true;
                }
            }
            if(!flag) dp[i]=dp[i-1];
            //cout << dp[i] << endl;
            umap[str[i]] = i+1;
        }

        unsigned long long int ans = 0;
        for(int i=0; i<str.size(); i++) ans = (ans%mod + dp[i]%mod)%mod;
        return ans;

    }
};
