// Roy and coin boxes DP problem Coding ninjas
// SlothyCoder16
// September 02, 2020

#include<bits/stdc++.h>
using namespace std;

int main(){
  typedef long long ll;
  ll n;
  cin >> n;
  ll m;
  cin >> m;


    int start[n];
    int end[n];

    for(int i=0; i<n; i++){
        start[i]=0;
        end[i]=0;
    }

    for(int i=0; i<m; i++){
        int l, r;
        cin >> l >> r;
        start[l-1]=start[l-1] + 1;
        end[r-1]=end[r-1] + 1;
    }

    int coins[n];
    coins[0]=start[0];
    for(int i=1; i<n; i++){
      coins[i]=coins[i-1] + start[i] - end[i-1];

    }

    int exact[n];
    for(int i=0; i<n; i++){
      exact[i]=0;
    }
    for(int i=0; i<n; i++){
      exact[coins[i]-1] = exact[coins[i]-1] + 1;
    }


    int least[n];
    least[n-1]=exact[n-1];
    for(int i=n-2; i>=0; i--){
      least[i] = least[i+1] + exact[i];
    }

    ll q;
    cin >> q;
    while(q--){
      ll x;
      cin >> x;
      cout << least[x-1] << endl;
    }
  }
