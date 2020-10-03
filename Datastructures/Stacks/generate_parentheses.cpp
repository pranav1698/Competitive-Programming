// Generate all Parentheses
// SlothyCoder16
// October 03, 2020

int Solution::isValid(string A) {
    stack<char> s;

    for(int i=0; i<A.size(); i++) {
        if(A[i]=='(' || A[i]=='{' || A[i]=='[') {
            s.push(A[i]);
        } else {
            if(!s.empty()) {
                char curr=s.top();
                s.pop();
                if(curr=='(' && A[i]!=')') {
                    return 0;
                } else if(curr=='{' && A[i]!='}') {
                    return 0;
                } else if(curr=='[' && A[i]!=']') {
                    return 0;
                }
            } else {
                return 0;
            }

        }
    }

    return s.empty();
}
