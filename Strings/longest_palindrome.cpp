// Given a string find the longest palindrome
// SlothyCoder16
// August 14, 2020

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> umap;
        for(int i=0; i<s.length(); i++) {
            umap[s[i]] = umap[s[i]] + 1;
        }

        int res = 0;
        bool flag = false;
        unordered_map<char, int>::iterator it = umap.begin();
        while(it != umap.end()) {
            if((it->second & 1) == 0) {
                res = res + it->second;
            } else {
                res = res + (it->second - 1);
                flag = true;
            }
            it++;
        }

        if(flag) return res+1;

        return res;
    }
};
