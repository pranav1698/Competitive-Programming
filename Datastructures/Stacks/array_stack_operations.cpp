// Making an array of stack operations
// SlothyCoder16
// July 17, 2020

class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;

        int j=0;
        for(int i=1; i<=n; i++) {
            if(j<target.size()) {
                if(target[j] == i) {
                    res.push_back("Push");
                    j++;
                } else {
                    res.push_back("Push");
                    res.push_back("Pop");
                }
            }
        }

        return res;
    }
};
