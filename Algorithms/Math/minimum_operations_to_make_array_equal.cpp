// Minimum operations to make array equal
// SlothyCoder16
// August 22, 2020

class Solution {
public:
    int minOperations(int n) {
        int min = 1;
        int max = (2*(n-1)) + 1;
        int mid = (min + max) / 2;
        int res = 0;
        for(int i=0; i<n/2; i++) {
            res = res + (mid - (2*i + 1));
        }

        return res;
    }
};
