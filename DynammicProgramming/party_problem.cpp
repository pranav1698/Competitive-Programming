// Maximum fun going to party given a budget
// SlothyCoder16
// September 04, 2020 

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int budget, n;
    cin >> budget >> n;

    while(budget!=0 && n!=0) {
    	vector<int> costs;
    	vector<int> funs;
    	int c, f;
    	for(int i=0; i<n; i++) {
        	cin >> c >> f;
        	costs.push_back(c);
        	funs.push_back(f);
    	}
        vector<vector<int>> dp(2, vector<int>(budget+1, 0));

        int flag=1;
        for(int i=0; i<n; i++) {
            for(int j=1; j<=budget; j++) {
                if(j >= costs[i]) {
                    dp[flag][j] = max(dp[flag^1][j], dp[flag^1][j-costs[i]] + funs[i]);
                } else {
                    dp[flag][j] = dp[flag^1][j];
                }
            }
            flag = flag^1;
        }
        int maxFun = dp[flag^1][budget];
        int minCost;
        for(int j=1;j<=budget; j++) {
        	if(dp[flag^1][j] == maxFun) {
            	minCost = j;
                break;
            }
        }
        cout << minCost << " " << maxFun << endl;


        cin >> budget >> n;
    }
}
