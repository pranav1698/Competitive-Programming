// Making binary  prefixes that are divisible by 5
// SlothyCoder16
// September 20, 2020

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> t;
        int x = 0;
        for(int i:A) {
            x<<=1, x|=i;
            t.push_back(x%5==0);
            x%=5;
        }
        return t;

    }
};
