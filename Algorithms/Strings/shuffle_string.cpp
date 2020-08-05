// Shuffle string as per indices array
// SlothyCoder16
// August 05, 2020

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string res = s;

        for(int i=0; i<indices.size(); i++) {
            res[indices[i]] = s[i];
        }

        return res;
    }
};
