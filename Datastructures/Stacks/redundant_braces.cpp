// Redundant braces
// SlothyCoder16
// October 05, 2020

int Solution::braces(string A) {
    stack<char> s;

    for(int i=0; i<A.size(); i++) {
        if(A[i]!=')') {
            s.push(A[i]);
        } else {
            string exp="";
            while(!s.empty() && s.top()!='(') {
                exp += s.top();
                s.pop();
            }
            s.pop();
            if(exp=="") return 1;
            else if(exp.find('+')==string::npos && exp.find('-')==string::npos && exp.find('*')==string::npos && exp.find('/')==string::npos) return 1;
        }
    }

    return 0;
}
