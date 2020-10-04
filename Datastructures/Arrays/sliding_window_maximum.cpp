// Sliding Window Maximum
// SlothyCoder16
// October 05, 2020

vector<int> Solution::slidingMaximum(const vector<int> &A, int B) {
    int i=0;
    int j=B;
    int max_ele=INT_MIN;
    vector<int> res;
    if(B>A.size()) {
        for(int i=0; i<A.size(); i++) max_ele=max(max_ele, A[i]);
        return {max_ele};
    }
    for(int k=0; k<j; k++) max_ele=max(max_ele, A[k]);
    res.push_back(max_ele);

    while(j<A.size()) {
        if(max_ele == A[i]) {
            max_ele=INT_MIN;
            for(int k=i+1; k<=j; k++) {
                max_ele=max(max_ele, A[k]);
            }
        } else {
            max_ele=max(max_ele, A[j]);
        }
        res.push_back(max_ele);
        i++;
        j++;
    }

    return res;
}
