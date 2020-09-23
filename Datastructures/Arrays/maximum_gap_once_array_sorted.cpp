// Finding maximum gap between consecutive elements in sorted array
// SlothyCoder16
// September 24, 2020

// O(N+range) time and O(N+range) space
int Solution::maximumGap(const vector<int> &A) {
    if(A.size() < 2) return 0;

    int max_num=INT_MIN;
    for(int i=0; i<A.size(); i++) max_num = max(max_num, A[i]);
    int min_num=INT_MAX;
    for(int i=0; i<A.size(); i++) min_num = min(min_num, A[i]);

    int range=(max_num-min_num)+1;
    vector<int> holes(range+1, -1);
    for(int i=0; i<A.size(); i++) {
        holes[A[i]-min_num]=A[i];
    }

    int i=0, j=1;
    int maxDiff=INT_MIN;
    while(i<=range && j<=range) {
        if(holes[i]!=-1 && holes[j]!=-1) {
            maxDiff = max(maxDiff, holes[j]-holes[i]);
            i++;
            j++;
        } else if(holes[j] == -1) {
            j++;
        } else if(holes[i] == -1) {
            i++;
        } else if(holes[i]==-1 && holes[j]==-1) {
            i++;
            j++;
        }
    }

    return maxDiff;
}

// O(N) time and O(N) space
int Solution::maximumGap(const vector<int> &A) {
    if(A.size() < 2) return 0;

    int n=A.size();
    int max_num=INT_MIN;
    for(int i=0; i<A.size(); i++) max_num = max(max_num, A[i]);
    int min_num=INT_MAX;
    for(int i=0; i<A.size(); i++) min_num = min(min_num, A[i]);

    float delta= (float)(max_num-min_num)/(float)(n-1);
    vector<int> maxGap(n-1, INT_MIN);
    vector<int> minGap(n-1, INT_MAX);

    for(int i=0; i<n; i++) {
        if(A[i]==max_num || A[i]==min_num) continue;

        int index=(float)(floor(A[i]-min_num) / delta);
        maxGap[index]=max(maxGap[index], A[i]);
        minGap[index]=min(minGap[index], A[i]);
    }

    int prevVal=min_num;
    int maxDiff=0;
    for(int i=0; i<n-1; i++) {
        if(minGap[i] == INT_MAX) continue;

        maxDiff=max(maxDiff, minGap[i]-prevVal);
        prevVal=maxGap[i];
    }
    maxDiff=max(maxDiff, max_num-prevVal);

    return maxDiff;
}
