// Hasan and trip coding ninjas problem
// SlothyCoder16
// September 02, 2020

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
   	vector<vector<float>> dist(n, vector<float>(n, 0));
    vector<int> x;
    vector<int> y;
    vector<int> h;

    int s, e, f;
    for(int i=0; i<n; i++) {
        cin >> s >> e >> f;
        x.push_back(s);
        y.push_back(e);
        h.push_back(f);
        for(int j=0; j<i; j++) {
        	float distance = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
            dist[i][j] = distance;
            dist[j][i] = distance;
        }
    }

    vector<float> dp(n, INT_MIN);
    dp[0] = h[0];
    dp[1] = h[0] + h[1] - dist[0][1];

    for(int i=2; i<n; i++) {
        for(int j=0; j<i; j++) {
        	dp[i] = max(dp[i], dp[j] + h[i] - dist[j][i]);
        }
    }

    printf("%06f", dp[n-1]);
}
