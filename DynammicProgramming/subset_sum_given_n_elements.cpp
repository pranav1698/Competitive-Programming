// Finding if subset sum possible using given array
// SlothyCoder16
// September 04, 2020

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n, 0);
    for(int i=0; i<n; i++) cin >> arr[i];
    int sum;
    cin >> sum;

    vector<vector<bool>> dp(2, vector<bool>(sum+1, false));
    dp[0][0]=true;
    dp[1][0] = true;
    for(int j=1; j<=sum; j++) dp[0][j] = false;

    int flag = 1;
    for(int i=1; i<=n; i++) {
        for(int j=0; j<=sum; j++) {
            if(j>=arr[i-1]) {
                dp[flag][j] = dp[flag^1][j] || dp[flag^1][j-arr[i-1]];
            } else {
                dp[flag][j] = dp[flag^1][j];
            }
        }
        flag = flag^1;
    }

    if(dp[flag^1][sum]) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
