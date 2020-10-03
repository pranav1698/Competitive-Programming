// Reverse string using stack
// SlothyCoder16
// October 03, 2020

string Solution::reverseString(string A) {
    stack<char> s;

    for(int i=0; i<A.size(); i++) {
        s.push(A[i]);
    }

    string res="";
    while(!s.empty()) {
        res += s.top();
        s.pop();
    }

    return res;
}
