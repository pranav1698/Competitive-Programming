  // Nearest smallest element
  // SlothyCoder16
  // October 04, 2020


vector<int> Solution::prevSmaller(vector<int> &A) {
    vector<int> res;
    if(A.size()==0) return res;
    stack<int> s;

    for(int i=0; i<A.size(); i++) {
        while(!s.empty() && s.top()>=A[i]) {
            s.pop();
        }
        if(s.empty()) res.push_back(-1);
        else res.push_back(s.top());
        s.push(A[i]);
    }

    return res;
}
