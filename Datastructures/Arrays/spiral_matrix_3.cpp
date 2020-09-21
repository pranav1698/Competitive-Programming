// Spiral Matrix Formation 
// SlothyCoder16
// September 21, 2020

vector<vector<int> > Solution::generateMatrix(int A) {
    vector<vector<int>> res(A, vector<int>(A, 0));
    int limit=A*A;
    int count=1;
    int top=0;
    int left=0;
    int right=A-1;
    int bottom=A-1;

    while(top<=bottom && left<=right) {
        for(int i=left; i<=right; i++) {
            res[top][i]=count;
            count++;
        }
        top++;

        for(int i=top; i<=bottom; i++) {
            res[i][right]=count;
            count++;
        }
        right--;

        if(top<=bottom) {
            for(int i=right; i>=left; i--) {
                res[bottom][i]=count;
                count++;
            }
            bottom--;
        }

        if(left<=right) {
            for(int i=bottom; i>=top; i--) {
                res[i][left]=count;
                count++;
            }
            left++;
        }
    }

    return res;
}
