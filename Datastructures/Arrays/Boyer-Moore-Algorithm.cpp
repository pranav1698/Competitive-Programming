// Boyer Moore Algorithm to find majority element in an array
// SlothyCoder16
// July 11, 2020


int Solution::repeatedNumber(const vector<int> &A) {
    int count=0;
    int num=INT_MAX;

    for(int i=0; i<A.size(); i++) {
        if(num==A[i]) {
            count++;
        } else if(count == 0) {
            count=1;
            num=A[i];
        } else {
            count--;
        }
    }

    count=0;
    for(int i=0; i<A.size(); i++) if(A[i]==num) count++;

    if(count>A.size()/3) return num;
    return -1;
}
