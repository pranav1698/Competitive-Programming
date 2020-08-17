#include <bits/stdc++.h>
using namespace std;

vector<string> getMiddle(int n, int n_length) {
  if(n == 0) return {""};
  if(n == 1) return {"0", "1", "8"};

  vector<string> middles = getMiddle(n - 2, n_length);
  vector<string> res;

  for(int i=0; i<middles.size(); i++) {
    if(n != n_length) res.push_back("0" + middles[i] + "0");

    res.push_back("1" + middles[i] + "1");
    res.push_back("8" + middles[i] + "8");
    res.push_back("6" + middles[i] + "9");
    res.push_back("9" + middles[i] + "6");
  }

  return res;
}

int main() {
  int n;
  cin >> n;
  vector<string> ans = getMiddle(n, n);

  for(int i=0; i<ans.size(); i++) cout << ans[i] << endl;
}
