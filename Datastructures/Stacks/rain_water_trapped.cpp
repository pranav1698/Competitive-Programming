// Rainwater trapped in the given histogram
// SlothyCoder16
// October 05, 2020

int Solution::trap(const vector<int> &A) {
    vector<int> left;
    stack<int> leftS;
    for(int i=0; i<A.size(); i++) {
        while(!leftS.empty() && leftS.top()<=A[i]) {
            leftS.pop();
        }
        if(leftS.empty()) leftS.push(A[i]);
        left.push_back(leftS.top());
    }

    vector<int> right(A.size());
    stack<int> rightS;
    for(int i=A.size()-1; i>=0; i--) {
        while(!rightS.empty() && rightS.top() <= A[i]) {
            rightS.pop();
        }
        if(rightS.empty()) rightS.push(A[i]);
        right[i]=rightS.top();
    }

    int trapped=0;
    for(int i=0; i<A.size(); i++) {
        int min_bound=min(left[i], right[i]);
        trapped += min_bound-A[i];
    }

    return trapped;
}
