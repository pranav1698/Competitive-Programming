// Count unique numbers in an n digit number
// SlothyCoder16
// August 19, 2020

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int ans = 1;
        vector<int> dp(10, 0);
        dp[0] = 1;
        dp[1] = 1;

        for(int i=2; i<=9; i++){
            dp[i] = i * dp[i-1];
        }

        for(int i=1; i<=n; i++) {
            ans = ans + (9 * dp[9] / dp[10-i]);
        }

        return ans;
    }
};
