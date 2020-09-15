// Modify Strings
// SlothyCoder16
// September 15, 2020

class Solution {
public:
    string modifyString(string s) {
        for(int i=0; i<s.size(); i++) {
            if(s[i] == '?') {
                bool flag=false;
                for(char j='a'; j<='z'; j++) {
                    if(i==0){
                        if(s[i+1] != j) {
                            s[i]=j;
                            break;
                        }
                    } else if(i == s.size()-1) {
                        if(s[i-1] != j) {
                            s[i]=j;
                            break;
                        }
                    } else {
                        if(s[i-1]!=j && s[i+1]!= j) {
                            s[i]=j;
                            break;
                        }
                    }
                }
            }
        }

        return s;
    }
};
