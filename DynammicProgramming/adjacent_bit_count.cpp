// Adjacent Bit count using dynammic programming
// SlothyCoder16
// September 08, 2020

#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main() {
  int t;
  cin >> t;
  while(t--) {
    int T, n, k;
    cin >> T >> n >> k;
    int dp[n+1][k+1][2];

    for(int i=0; i<=n; i++){
      for(int j=0; j<=k; j++) {
        for(int l=0; l<2; l++) {
          dp[i][j][l] = 0;
        }
      }
    }

    dp[1][0][1] = 1;
    dp[1][0][0] = 1;

    for(int i=2; i<=n; i++) {
      for(int j=0; j<=k; j++) {
    	dp[i][j][0] = dp[i-1][j][0] + dp[i-1][j][1];
        if(dp[i][j][0] >= mod) dp[i][j][0] -= mod;
        if(j == 0) {
            dp[i][j][1] = dp[i-1][j][0];
        } else {
            dp[i][j][1] = dp[i-1][j-1][1] + dp[i-1][j][0];
        }
        if(dp[i][j][1] >= mod) dp[i][j][1] -= mod;
      }
    }

    unsigned long long int ans  = dp[n][k][0] + dp[n][k][1];
    if(ans >= mod) ans-= mod;
    cout << T << " " << ans << endl;
  }
}
