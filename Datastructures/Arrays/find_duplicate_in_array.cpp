// Finding duplicate in array
// SlothyCoder16
// September 23, 2020

// O(N) time and O(N) space
int Solution::repeatedNumber(const vector<int> &A) {
    vector<int> freq(A.size()+1, 0);
    for(int i=0; i<A.size(); i++) freq[A[i]]+=1;
    for(int i=1; i<=A.size(); i++) if(freq[i] > 1) return i;

    return -1;
}

// O(N) and O(1) space
int Solution::repeatedNumber(const vector<int> &A) {
    int n=A.size();
    for(int i=0; i<A.size(); i++) A[A[i]%n]+=n;
    for(int i=1; i<=A.size(); i++) if(A[i]/n > 1) return i;

    return -1;
}
