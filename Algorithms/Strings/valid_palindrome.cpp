// Check if string is Palindrome
// SlothyCoder16
// August 04, 2020

class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;

        while(end > start) {
            if(isalnum(s[start]) && isalnum(s[end])) {
                if(tolower(s[start]) != tolower(s[end])) {
                    return false;
                }
                start++;
                end--;
            } else if(!isalnum(s[start])) {
                start++;
            } else if(!isalnum(s[end])) {
                end--;
            }
        }

        return true;
    }
};
