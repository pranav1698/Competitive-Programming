// Jon Snow and his favorite number
// SlothyCoder16
// September 03, 2020

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, x;
    cin >> n >> k >> x;
    vector<int> freq(1024, 0);

    int ma=0;
    for(int i=0; i<n; i++) {
        int curr;
        cin >> curr;
        ma = max(ma, curr);
        ma = max(ma, curr^x);
        freq[curr] = freq[curr] + 1;
    }

    ma = min(ma*2, 1023);
    vector<int> count(1024, 0);
	while(k--) {
        int curr_j = 0;
        for(int i=0; i<=ma; i++) {
            if(freq[i] != 0) {
                int a = freq[i];
                if((a&1) == 0) {
                    freq[i] -= (a/2);
                    count[i] += freq[i];
                    count[x^i] += (a/2);
                } else {
                    if((curr_j&1) == 0) {
                        freq[i] -= (a/2+1);
                        count[i] += freq[i];
                        count[x^i] += (a/2+1);
                    } else {
                        freq[i] -= (a/2);
                        count[i] += freq[i];
                        count[x^i] += (a/2);
                    }
                }
                curr_j += a;
            }
        }
        freq = count;
        for(int i=0; i<=ma; i++) count[i] = 0;
    }

    int min_ele, max_ele;
    for(int i=0; i<=ma; i++) {
        if(freq[i] > 0) {
            min_ele = i;
            break;
        }
    }

    for(int i=ma; i>=0; i--) {
        if(freq[i] > 0) {
            max_ele = i;
            break;
        }
    }

    cout << max_ele << " " << min_ele << endl;

    return 0;
}
