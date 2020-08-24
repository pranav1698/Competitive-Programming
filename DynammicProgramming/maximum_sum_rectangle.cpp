// Maximum sum reactangle you can form using 2d matrix
// SlothyCoder16
// August 24, 2020

#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> nums) {
  int curr = 0;
  int best = INT_MIN;
  int me = INT_MIN;

  for(int i=0; i<nums.size(); i++) {
    curr = curr + nums[i];
    if(curr < 0) curr = 0;
    best = max(curr, best);
    me = max(me, nums[i]);
  }

  if(me < 0) return me;
  return best;
}

int main() {
  int n, m;
  cin >> n >> m;

  int M[n][m];
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      cin >> M[i][j];

  int mxsum = INT_MIN;
  for(int l=0; l<m; l++) {
    vector<int> v(n, 0);
    for(int r=l; r<n; r++) {
      for(int i=0; i<n; i++)
        v[i] += M[i][r];
      mxsum = max(mxsum, kadane(v));
    }
  }

  cout << mxsum << endl;
}
