// Repetition of substrings to form the string
// SlothyCoder16
// September 03, 2020

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        // Concatenation of substrings
        for(int i=1; i<=s.size()/2; i++) {
            string curr = s.substr(0, i);

            int temp = curr.size();
            if((s.size() % temp) == 0) {
                string s1 = "";
                int k = s.size() / temp;
                while(k--) {
                    s1 += curr;
                }
                if(s1 == s) return true;
            }
        }

        return false;

    }
};
