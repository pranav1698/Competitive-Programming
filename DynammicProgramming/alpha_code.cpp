// Alpha Code using DP
// SlothyCoder16
// August 23, 2020

class Solution {
public:
    int numDecodings(string s) {
        int dp[s.length()];
        if((s[0] - '0') == 0) return 0;
        dp[0]=1;

        for(int i=1; i<s.length(); i++) {
            if((s[i] - '0') != 0) {
                dp[i] = dp[i-1];
            } else {
                dp[i] = 0;
            }

            if((((s[i-1] - '0')*10) + (s[i] - '0')) >= 10 && (((s[i-1] - '0')*10) + (s[i] - '0')) <= 26) {
                if((s[i] - '0') != 0) {
                    if(i>=2) {
                        dp[i] = dp[i] + dp[i-2];
                    } else {
                        dp[i] = dp[i] + 1;
                    }
                } else {
                    if(i >= 2) {
                        dp[i] = dp[i-2];
                    } else {
                        dp[i] = dp[i-1];
                    }
                }
            }
        }

        return dp[s.length()-1];
    }
};
