// Maximum contiguous subarray sum
// SlothyCoder16
// September 08, 2020

int Solution::maxSubArray(const vector<int> &A) {
    int curr=0;
    int best=INT_MIN;
    int ret=INT_MIN;

    for(int i=0;i<A.size(); i++) {
        curr += A[i];
        if(curr<0) curr = 0;

        best=max(best, curr);
        ret=max(ret, A[i]);
    }

    if(ret<0) return ret;
    return best;
}
