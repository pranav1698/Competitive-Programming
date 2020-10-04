// Finding max prod using the left and right directions of array
// SlothyCoder16
// October 05, 2020

// O(n) Solution
int Solution::maxSpecialProduct(vector<int> &A) {
    stack<int> leftS;
    vector<int> left;
    for(int i=0; i<A.size(); i++) {
        while(!leftS.empty() && A[leftS.top()]<=A[i]) {
            leftS.pop();
        }
        if(leftS.empty()) left.push_back(0);
        else left.push_back(leftS.top());
        leftS.push(i);
    }

    stack<int> rightS;
    vector<int> right(A.size());
    for(int i=A.size()-1; i>=0; i--) {
        while(!rightS.empty() && A[rightS.top()]<=A[i]) {
            rightS.pop();
        }
        if(rightS.empty()) right[i]=0;
        else right[i]=rightS.top();
        rightS.push(i);
    }

    long long max_ele=-1;
    for(int i=0; i<A.size(); i++) {
        max_ele=max(max_ele, left[i]*1LL*right[i]);
    }

    return max_ele%(1000000007);
}
