// Finding length of repeated subarray
// SlothyCoder16
// September 18, 2020

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int n=A.size(), m=B.size();
        int dp[n+1][m+1];
        for(int i=0; i<=m; i++) dp[0][i]=0;
        for(int i=0; i<=n; i++) dp[i][0]=0;
        int ans=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(A[i-1]==B[j-1]){ dp[i][j]=1+dp[i-1][j-1]; ans=max(ans,dp[i][j]); }
                else dp[i][j]=0;
            }
        }
        return ans;
    }
};
