// Implementation of reverse polish notation using stack
// SlothyCoder16
// July 18, 2020

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> results;
        int a,b;

        for(int i=0; i<tokens.size(); i++) {
            if(tokens[i] == "+") {
                if(!results.empty()){
                    a = results.top();
                    results.pop();
                    b = results.top();
                    results.pop();
                }
                results.push(b + a);
            } else if(tokens[i] == "*") {
                if(!results.empty()){
                    a = results.top();
                    results.pop();
                    b = results.top();
                    results.pop();
                }
                results.push(b * a);
            } else if(tokens[i] == "/") {
                if(!results.empty()){
                    a = results.top();
                    results.pop();
                    b = results.top();
                    results.pop();
                }
                results.push(b / a);
            } else if(tokens[i] == "-") {
                if(!results.empty()){
                    a = results.top();
                    results.pop();
                    b = results.top();
                    results.pop();
                }
                results.push(b - a);
            } else {
                int x=0;
                stringstream geek(tokens[i]);
                geek >> x;
                results.push(x);
            }
        }

        int res = results.top();
        results.pop();

        return res;
    }
};
