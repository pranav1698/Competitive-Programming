// Check if the given number is palindrome
// SlothyCoder16
// August 29, 2020

class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        string s = to_string(x);

        for(int i=0; i<=s.length()/2; i++) {
            if(s[i] != s[s.length()-i-1]) return false;
        }

        return true;
    }
};
