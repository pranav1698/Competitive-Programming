// Generating valid parentheses pair using recursion
// SlothyCoder16
// August 18, 2020

class Solution {
public:
    vector<string> ans;

    void makeValidParentheses(string soFar, int openNum, int closeNum) {
        if(openNum == 0) {
            for(int i=0; i<closeNum; i++) soFar = soFar + ')';
            ans.push_back(soFar);
            return;
        }

        if(openNum == closeNum) {
            soFar = soFar + '(';
            makeValidParentheses(soFar, openNum-1, closeNum);
        } else {
            makeValidParentheses(soFar + '(', openNum-1, closeNum);
            makeValidParentheses(soFar + ')', openNum, closeNum-1);
        }
    }


    vector<string> generateParenthesis(int n) {
        makeValidParentheses("", n, n);
        return ans;
    }
};
