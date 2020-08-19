// Translating sentence to goat latin
// SlothyCoder16
// August 19, 2020

class Solution {
public:
    string toGoatLatin(string S) {
        string ex="";
        int count=0;
        string s="";
        string ans="";
        for(int i=0; i<S.length(); i++) {
            if(S[i] == ' ') {
                count++;
                s="";
                string curr = ex;
                char first = curr[0];
                if(first == 'a' || first == 'A' || first == 'e' || first == 'E' || first == 'i' || first == 'I' || first == 'o' || first == 'O' || first == 'u' || first == 'U') {
                    s = curr;
                    s = s + 'm';
                    s = s + 'a';
                } else {
                    s = s + curr.substr(1);
                    s = s + first;
                    s = s + 'm';
                    s = s + 'a';
                }

                int c = count;
                while(c--) {
                    s = s + 'a';
                }
                ans = ans + s + ' ';
                ex="";
            } else {
                ex = ex + S[i];
            }
        }
        count++;
        s="";
        char first = ex[0];
        if(first == 'a' || first == 'A' || first == 'e' || first == 'E' || first == 'i' || first == 'I' || first == 'o' || first == 'O' || first == 'u' || first == 'U') {
            s = ex;
            s = s + 'm';
            s = s + 'a';
        } else {
            s = s + ex.substr(1);
            s = s + first;
            s = s + 'm';
            s = s + 'a';
        }

        int c = count;
        while(c--) {
            s = s + 'a';
        }
        ans = ans + s;

        return ans;
    }
};
