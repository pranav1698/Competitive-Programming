// Charlie and pilots coding ninjas question
// SlothyCoder16
// September 06, 2020

#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;

int findMin(int n, vector<int> &a, int ra, vector<int> &c, int rc, int rem, int x, vector<vector<ll>> &dp) {
    if(rem <= 0) return 0;
    if(dp[n][x] > -1) return dp[n][x];
    if(x==0) return a[n-ra] + findMin(n, a, ra-1, c, rc-1, rem-1, 1, dp);
    if(x==rem) return c[n-rc] + findMin(n,a,ra-1,c,rc-1,rem-1, x-1, dp);

    int option1 = a[n-ra] + findMin(n, a, ra-1, c, rc-1, rem-1, x+1, dp);
    int option2 = c[n-rc] + findMin(n, a, ra-1, c, rc-1, rem-1, x-1, dp);

    dp[n][x] = min(option1, option2);
    return dp[n][x];
}

int main()
{
    int n;
    cin >> n;
    vector<int> c;
    vector<int> a;
    int cs, as;
    for(int i=0; i<n; i++) {
        cin >> cs >> as;
        c.push_back(cs);
        a.push_back(as);
    }

    vector<vector<ll>> dp(n+1, vector<ll>(100000, -1));
    cout << findMin(n, a, n, c, n, n, 0, dp) << endl;
    return 0;
}
