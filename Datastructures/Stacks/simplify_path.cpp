// Simplify Path using c++ stack
// SlothyCoder16
// July 17, 2020

class Solution {
public:
    string simplifyPath(string path) {
        string res = "/";
        stack <string> s;

        string substr = "";
        for(int i=0; i<path.length(); i++){
            if(path[i] == '/') {
                if(substr.length() != 0 && substr != "."){
                    if(substr == "..") {
                        if(!s.empty()){
                            s.pop();
                            s.pop();
                        }
                    }
                    if(substr != "..") {
                        s.push(substr);
                        s.push("/");
                    }
                }
                substr = "";
            } else {
                substr = substr + path[i];
            }

            if(i == path.length() - 1) {
                if(substr.length() != 0 && substr != "."){
                    if(substr == "..") {
                         if(!s.empty()){
                            s.pop();
                            s.pop();
                        }
                    }
                    if(substr != "..") {
                        s.push(substr);
                        s.push("/");
                    }
                }
            }
        }

       if(!s.empty())
            s.pop();
        vector<string> finalRes;
        while(!s.empty()) {
            finalRes.push_back(s.top());
            s.pop();
        }

        for(int i=finalRes.size()-1; i>=0; i--)
            res = res + finalRes[i];

        return res;
    }
};
