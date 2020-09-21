// Maximum unsorted subarray
// SlothyCoder16
// September 22, 2020

// O(NlogN) approach
vector<int> Solution::subUnsort(vector<int> &A) {
    int i=A.size()-1;
    int j=0;
    vector<int> temp=A;

    sort(temp.begin(), temp.end());
    for(int k=0; k<temp.size(); k++) {
        if(A[k] != temp[k]) {
            i=min(k,i);
            j=max(k,j);
        }
    }

    if(i==A.size()-1 && j==0) return {-1};
    return {i,j};
}

// O(n) and O(1) space
vector<int> Solution::subUnsort(vector<int> &A) {
    int i=0;
    int j=A.size()-1;

    while(i<A.size()-1 && A[i]<=A[i+1]) i++;
    while(j>0 && A[j]>=A[j-1]) j--;

    if(i==A.size()-1) return {-1};
    int mx=A[i];
    int mn=A[i];
    for(int k=i; k<=j; k++) {
        mn=min(A[k], mn);
        mx=max(A[k], mx);
    }

    int l=0, r=A.size()-1;
    while(l<=i && A[l]<=mn) l++;
    while(r>=i && A[r]>=mx) r--;

    return {l,r};
}
