#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	while(n--) {
	    int activities;
	    cin >> activities;
	    vector<int> s;
	    vector<int> f;
	    for(int i=0; i<activities; i++) {
	        int start;
	        cin >> start;
	        s.push_back(start);
	    }

	    for(int i=0; i<activities; i++) {
	        int finish;
	        cin >> finish;
	        f.push_back(finish);
	    }

	    vector<vector<int>> acts;
	    for(int i=0; i<activities; i++) acts.push_back({s[i], f[i]});
	    sort(acts.begin(), acts.end(), [](const vector<int> i1, const vector<int> i2){
            return i1[1] < i2[1];
        });

        int ans = 1;
        int start = acts[0][0], end = acts[0][1];
        for(int i=1; i<acts.size(); i++) {
            vector<int> s = acts[i];
            if(end <= s[0]){
                ans++;
                start = s[0];
                end = s[1];
            }
        }

        cout << ans << endl;

	}
	return 0;
}
