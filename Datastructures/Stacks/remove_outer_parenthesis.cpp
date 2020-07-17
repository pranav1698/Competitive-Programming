// Implementation of removing outer parenthesis from string without using stack
// SlothyCoder16
// July 17, 2020


class Solution {
public:
   string removeOuterParentheses(string S) {
        string res;
        int opened = 0;
        for (char c : S) {
            if (c == '(' && opened++ > 0) res += c;
            if (c == ')' && opened-- > 1) res += c;
        }
        return res;
    }
};
