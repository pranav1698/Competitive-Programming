// Simplify UNIX path
// SlothyCoder16
// October 04, 2020

string Solution::simplifyPath(string A) {
    string res="";
    string s="";
    stack<string> st;

    for(int i=1; i<A.size(); i++) {
        if(A[i]=='/') {
            if(s==".") {
                s="";
            } else if(s=="..") {
                if(!st.empty()) {
                    st.pop();
                }
                s="";
            } else  {
                if(s!=""){
                    st.push(s);
                    s="";
                }
            }
        } else {
            s+=A[i];
        }
    }

    if(s!="") {
        if(s==".."){
            if(!st.empty()) st.pop();
        } else if(s==".") {
            s="";
        } else {
            st.push(s);
        }
    }

    vector<string> paths;
    while(!st.empty()) {
        paths.push_back(st.top());
        st.pop();
    }
    reverse(paths.begin(), paths.end());
    if(paths.size()==0) return "/";
    for(int i=0; i<paths.size(); i++) {
        res+='/';
        res+=paths[i];
    }

    return res;
}
