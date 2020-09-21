// Convert the array into wave array 
// SlothyCoder16
// September 21, 2020

vector<int> Solution::wave(vector<int> &A) {
    sort(A.begin(), A.end());

    int n=A.size();
    int i=0;
    int j=1;

    while(i<n && j<n) {
        swap(A[i], A[j]);
        i+=2;
        j+=2;
    }

    return A;
}
