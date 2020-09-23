// Maximum number of ones after fliiping subarrays
// SlothyCoder16
// September 24, 2020

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n;
	    cin >> n;
	    vector<int> arr(n,0);
	    for(int i=0; i<n; i++) cin >> arr[i];

	    int c=0;
	    for(int i=0; i<arr.size(); i++) if(arr[i] == 1) c++;
	    if(c==arr.size()) {
	        cout << c << endl;
	    } else {
	        int curr=0;
	        int mx=0;

	        for(int i=0; i<n; i++) {
	            if(arr[i]==0) {
    	            curr++;
    	        } else if(arr[i]==1) {
    	            curr--;
    	        }

    	        if(curr<0) {
    	            curr=0;
    	        }

    	        mx=max(curr, mx);
    	    }

    	    cout << mx+c << endl;
	    }
	}
	return 0;
}
