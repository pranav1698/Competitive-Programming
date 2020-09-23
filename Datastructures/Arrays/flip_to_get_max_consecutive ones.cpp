int kadane(string A, int l, int r) {
    int curr=0;
    int maxSum=0;
    for(int i=0; i<l; i++) {
        if(A[i]=='0') curr=0;
        else curr++;

        maxSum = max(curr, maxSum);
    }

    for(int i=l; i<=r; i++) {
        if(A[i] == '1') curr=0;
        else curr++;

        maxSum=max(maxSum, curr);
    }

    for(int i=r+1; i<A.size(); i++) {
        if(A[i]=='0') curr=0;
        else curr++;

        maxSum = max(curr, maxSum);
    }

    return maxSum;
}


vector<int> Solution::flip(string A) {
    int count=0;
    int maxSum=0;
    int L, R;
    for(int i=0; i<A.size(); i++) if(A[i]=='1') count++;
    if(count==A.size()) return {};

    for(int i=0; i<A.size()-1; i++) {
        for(int j=i; j<A.size(); j++) {
            if(kadane(A, i, j) > maxSum) {
                L=i+1;
                R=j+1;
                maxSum=kadane(A, i, j);
            }
        }
    }

    return {L,R};
}
