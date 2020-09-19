// Pick from both sides
// SlothyCoder16
// September 19, 2020

int Solution::solve(vector<int> &A, int B) {
    int n=A.size();
    vector<int> start(n, 0);
    vector<int> back(n, 0);
    if(n==0) return 0;
    if(B==0) return 0;
    if(B>n) return 0;
    if(n==1) return A[0];

    start[0]=A[0];
    for(int i=1; i<n; i++) start[i]=start[i-1]+A[i];
    back[n-1]=A[n-1];
    for(int i=n-2; i>=0; i--) back[i]=back[i+1]+A[i];

    int ans=start[B];
    for(int k=1; k<B; k++) {
        ans = max(ans, start[k-1]+back[n-B+k]);
    }
    ans = max(ans, back[B]);
    return ans;
}
