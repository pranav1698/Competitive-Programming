// Comapre versions
// SlothyCoder16
// September 07, 2020

class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> f;
        vector<int> s;

        string s1="", s2="";
        for(int i=0; i<version1.length(); i++) {
            if(version1[i] == '.'){
                int x;
                if(s1 == "") {
                    f.push_back(0);
                } else {
                    stringstream st(s1);
                    st >> x;
                    f.push_back(x);
                }
                s1="";
            } else {
                if(version1[i] != '0') s1+=version1[i];
                else if(version1[i] == '0') if(s1!="") s1+=version1[i];
            }
        }

        if(s1!="") {
            int x;
            stringstream st(s1);
            st >> x;
            f.push_back(x);
        } else {
            f.push_back(0);
        }

        for(int i=0; i<version2.length(); i++) {
            if(version2[i] == '.'){
                int x;
                if(s2 == "") {
                    s.push_back(0);
                } else {
                    stringstream st(s2);
                    st >> x;
                    s.push_back(x);
                }
                s2="";
            } else {
                if(version2[i] != '0') s2+=version2[i];
                else if(version2[i] == '0') if(s2!="") s2+=version2[i];
            }
        }

        if(s2!="") {
            int x;
            stringstream st(s2);
            st >> x;
            s.push_back(x);
        } else {
            s.push_back(0);
        }

        int start=0;
        while(start<f.size() && start<s.size()) {
            if(f[start] > s[start]) return 1;
            if(f[start] < s[start]) return -1;
            start++;
        }
        if(start==f.size() && start<s.size()) for(int i=start; i<s.size(); i++) if(s[i] != 0) return -1;
        if(start==s.size() && start<f.size()) for(int i=start; i<f.size(); i++) if(f[i] != 0) return 1;

        return 0;
    }
};
