// Word Pattern matching
// SlothyCoder16
// September 07, 2020

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int start = 1;
        int startc = 1;
        unordered_map<string, int> umap;
        unordered_map<char, int> cmap;
        string s="";

        string ans1="";
        string ans2="";
        for(int i=0; i<str.length(); i++) {
            if(str[i] == ' ') {
                if(umap[s] == 0) umap[s] = start;
                ans1 += to_string(umap[s]);
                start++;
                s="";
            } else {
                s+=str[i];
            }
        }
        if(umap[s] ==0) umap[s] = start;
        ans1 += to_string(umap[s]);
        for(int i=0; i<pattern.length(); i++) {
            if(cmap[pattern[i]] == 0) cmap[pattern[i]] = startc;
            startc++;
            ans2 += to_string(cmap[pattern[i]]);
        }

        return ans1 == ans2;
    }
};
