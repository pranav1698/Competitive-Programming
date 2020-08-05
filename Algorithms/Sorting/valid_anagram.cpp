// Checking valid anagram using sorting 
// SlothyCoder16
// August 05, 2020

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(t.length() != s.length()) return false;

        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return (s == t);
    }
};
