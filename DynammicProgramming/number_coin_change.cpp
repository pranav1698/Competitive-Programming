// Identifying total number of exchanges with a given number of coins and an amount
// SlothyCoder16
// August 24, 2020

#include <bits/stdc++.h>
using namespace std;

int countWaysToMakeChange(vector<int> coins, int amount) {
  int dp[coins.size()+1][amount+1];
  dp[0][0] = 0;
  for(int j=1; j<=amount; j++) dp[0][j] = 0;
  for(int i=1; i<=coins.size(); i++) dp[i][0] = 1;

  for(int i=1; i<=coins.size(); i++) {
    for(int j=1; j<=amount; j++) {
      dp[i][j] = dp[i-1][j];
      if(j >= coins[i-1]) {
        dp[i][j] += dp[i][j-coins[i-1]];
      }
    }
  }

  return dp[coins.size()][amount];
}

int main() {
  int n;
  cin >> n;
  vector<int> coins;
  int coin;
  for(int i=0; i<n; i++) {
    cin >> coin;
    coins.push_back(coin);
  }

  int amount;
  cin >> amount;

  cout << countWaysToMakeChange(coins, amount) << endl;
}
