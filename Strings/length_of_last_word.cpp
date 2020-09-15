// Length of last word
// SlothyCoder16
// September 15, 2020

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len=0;
        if(s == "") return 0;
        reverse(s.begin(), s.end());

        for(int i=0; i<s.size(); i++) {
            if(s[i] == ' ') {
                if(len != 0) break;
          } else {
                len++;
            }
        }

        return len;
    }
};
