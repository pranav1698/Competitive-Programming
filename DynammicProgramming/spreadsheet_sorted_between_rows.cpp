// Is the spreadsheet between two rows?
// SlothyCoder16
// September 03, 2020

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin >> n >> m;
    vector<vector<int>> arr(2, vector<int>(m, 0));
    vector<vector<int>> dp(2, vector<int>(m, 0));
    vector<int> Min(n, INT_MAX);

    for(int i=0; i<m; i++) {
        cin >> arr[0][i];
        dp[0][i] = 0;
        Min[0] = 0;
    }

    int flag = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<m; j++) {
        	cin >> arr[flag][j];
            if(arr[flag^1][j] <= arr[flag][j]) {
                dp[flag][j] = dp[flag^1][j];
            } else {
                dp[flag][j] = i;
            }
            Min[i] = min(Min[i], dp[flag][j]);
        }
        flag = flag^1;
    }

    int q, l, r;
    cin >> q;
    while(q--) {
        cin >> l >> r;
        if(Min[r-1] <= (l-1)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}
