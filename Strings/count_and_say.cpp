// Count frequency and say numbers
// SlothyCoder16
// September 07, 2020

class Solution {
public:
    string countAndSay(int n) {
        vector<string> dp(n, "");
        dp[0] = "1";

        for(int i=1; i<n; i++) {
            string prev=dp[i-1];
            int j=0;
            while(j<prev.size()) {
                int count=1;
                char a=prev[j];
                int t=j+1;
                while(prev[t] == a && t<prev.size()) {
                    count++;
                    t++;
                }
                dp[i]+=to_string(count) + a;
                if(t!=j+1) j=t;
                else j++;
            }
        }

        return dp[n-1];
    }
};
