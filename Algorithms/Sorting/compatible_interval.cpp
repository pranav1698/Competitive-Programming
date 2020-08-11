#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<vector<int>> jobs = {{1,10}, {2,4}, {3,5}, {5,7}, {8,10}, {10,11}};

  sort(jobs.begin(), jobs.end(), [](const vector<int> i1, const vector<int> i2){
    return i1[0] < i2[0];
  });


  vector<vector<int>> ans;
  for(int i=0; i<jobs.size()-1; i++) {
    vector<vector<int>> res;
    int start = jobs[i][0];
    int end = jobs[i][1];
    for(int j=i+1; j<jobs.size(); j++) {
      vector<int> s = jobs[j];

      if(end <= s[0]) {
        res.push_back({start, end});
        start = s[0];
        end = s[1];
      }
    }
    res.push_back({start, end});

    if(ans.size() < res.size()) ans = res;
  }

  for(int i=0; i<ans.size(); i++) {
    cout << ans[i][0] << " " << ans[i][1] << endl;
  }
}
