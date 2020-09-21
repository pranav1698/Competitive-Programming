// Rotate the matrix 90 degree clockwise
// SlothyCoder16
// September 22, 2020


void Solution::rotate(vector<vector<int> > &A) {
    int top=0;
    int bottom=A.size()-1;

    while(top < bottom) {
        for(int j=0; j<A[0].size(); j++) {
            swap(A[top][j], A[bottom][j]);
        }
        top++;
        bottom--;
    }

    for(int i=0; i<A.size(); i++) {
        for(int j=i+1; j<A[0].size(); j++) {
            swap(A[i][j], A[j][i]);
        }
    }
}
