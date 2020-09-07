// Reverse words in a string
// SlothyCoder16
// September 07, 2020

class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        if(s=="" || s==" ") return "";
        bool flag=false;
        for(int i=0; i<n; i++) if(s[i]!=' ') flag=true;
        if(!flag) return "";

        string rev="";
        string str="";
        for(int i=n-1; i>=0; i--) {
            if(s[i] == ' ') {
               if(str!="" && str!=" ") {
                   reverse(str.begin(), str.end());
                   rev+=str + " ";
               }
                str="";
            } else {
                str += s[i];
            }
        }

        cout << str << endl;
        if(str!="" && str!=" ") {
            reverse(str.begin(), str.end());
            rev+=str;
        }
        return rev[rev.size()-1] == ' ' ? rev.substr(0,  rev.size()-1) : rev;
    }
};
