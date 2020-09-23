// Finding the n/3 repeated number
// SlothyCoder16
// September 24, 2020

int Solution::repeatedNumber(const vector<int> &A) {
    int count1=0;
    int count2=0;
    int first=INT_MAX;
    int second=INT_MAX;

    for(int i=0; i<A.size(); i++) {
        if(first == A[i]) {
            count1++;
        } else if(second == A[i]) {
            count2++;
        } else if(count1 == 0) {
            count1=1;
            first=A[i];
        } else if(count2 == 0) {
            count2=1;
            second=A[i];
        } else {
            count1--;
            count2--;
        }
    }

    count1=0;
    count2=0;
    for(int i=0; i<A.size(); i++) {
        if(A[i]==first) count1++;
        if(A[i]==second) count2++;
    }

    if(count1>(A.size()/3)) return first;
    if(count2>(A.size()/3)) return second;

    return -1;
}
