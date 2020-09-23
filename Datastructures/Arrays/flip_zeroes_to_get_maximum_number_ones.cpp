// Flipping bits to get maximum number of ones
// SlothyCoder16
// September 23, 2020

// O(N^3) approach
vector<int> Solution::flip(string A) {
    int count=0;
    int maxCount=0;
    int L, R;
    for(int i=0; i<A.size(); i++) if(A[i]=='1') count++;
    if(count==A.size()) return {};

    int count2;
    for(int i=0; i<A.size()-1; i++) {
        for(int j=i; j<A.size(); j++) {
            count2=count;
            for(int k=i; k<=j; k++) {
                if(A[k]=='0') count2++;
                else if (A[k] == '1') count2--;
            }
            if(count2 > maxCount) {
                maxCount = count2;
                L=i+1;
                R=j+1;
            }
        }
    }

    return {L,R};
}

// O(N) approach kadane's algorithm
vector<int> Solution::flip(string A) {
    int currCount=0;
    int maxCount=0;
    int L=0;
    int R=0;
    int l=0;
    int r=0;
    int c=0;
    for(int i=0; i<A.size(); i++) if(A[i]=='1') c++;
    if(c==A.size()) return {};

    for(int i=0; i<A.size(); i++) {
        if(A[i] == '0') {
            currCount++;
        } else if(A[i] == '1') {
            currCount--;
        }

        if(currCount < 0) {
            currCount=0;
            l=i+1;
            r=i+1;
        } else {
            r=i;
        }

        if(currCount>maxCount) {
            maxCount=currCount;
            L=l+1;
            R=r+1;
        }
    }

    return {L,R};
}
