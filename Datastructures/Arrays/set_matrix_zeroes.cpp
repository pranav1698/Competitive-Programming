// Set Matrix Zeroes
// SlothyCoder16
// September 19, 2020


void Solution::setZeroes(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    vector<bool> isZeros(m+n, false);

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(A[i][j] == 0) {
                isZeros[i]=true;
                isZeros[j+m] = true;
            }
        }
    }

    for(int i=0; i<m; i++) {
        if(isZeros[i]) {
            for(int j=0; j<n; j++) A[i][j] = 0;
        }
    }

    for(int j=m; j<m+n; j++) {
        if(isZeros[j]) {
            for(int i=0; i<m; i++) A[i][j-m]=0;
        }
    }
}
