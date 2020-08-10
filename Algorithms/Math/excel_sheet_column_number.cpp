// Finding excel sheet column number of alphabet combinations
// SlothyCoder16
// August 10, 2020


class Solution {
public:
    int titleToNumber(string s) {
        int title = 0;
        int n = s.length();
        for(int i=s.length() -1; i>=0; i--) {
            title += pow(26, n-i-1) * ((int)s[i] - 64);
        }

        return title;
    }
};
