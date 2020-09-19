// Perfect peak of the array
// SlothyCoder16
// September 19, 2020

int Solution::perfectPeak(vector<int> &A) {
    vector<bool> satisfy(A.size(), false);
    int max=A[0];

    for(int i=1; i<A.size()-1; i++) {
        if(A[i] > max) {
            satisfy[i]=true;
            max=A[i];
        }
    }

    int min=A[A.size()-1];
    for(int i=A.size()-2; i>0; i--) {
        if(A[i]<min) {
            if(satisfy[i]) return 1;
            min = A[i];
        }
    }

    return 0;
}
