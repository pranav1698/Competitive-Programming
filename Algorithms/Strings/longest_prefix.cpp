// Find Longest Prefix in an array of strings
// SlothyCoder16
// August 29, 2020

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        string longPrefix = strs[0];

        for(int i=1; i<strs.size(); i++) {
            string curr = strs[i];
            int j=0;
            while(j<curr.length()) {
                if(curr[j] != longPrefix[j]) {
                    break;
                }
                j++;
            }
            longPrefix = longPrefix.substr(0, j);
        }

        return longPrefix;
    }
};
