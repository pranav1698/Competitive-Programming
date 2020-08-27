// Printing a matrix spirally
// SlothyCoder16
// August 28, 2020

#include <bits/stdc++.h>
using namespace std;

void printSpiral(int** mat, int top, int bottom, int left, int right) {
    while(top <= bottom && left <= right) {
        for(int i=left; i<=right; i++)
            cout << mat[top][i] << " ";
        top++;

        for(int i=top; i<=bottom; i++)
            cout << mat[i][right] << " ";
        right--;

        if(top <= bottom) {
            for(int i=right; i>=left; i--)
                cout << mat[bottom][i] << " ";
            bottom--;
        }

        if(left <= right) {
            for(int i=bottom; i>=top; i--) {
                cout << mat[i][left] << " ";
            }
            left++;
        }
    }

    return;
}

int main() {
	int n;
	cin >> n;
	while(n--) {
	    int r, c;
	    cin >> r >> c;
	    int** mat = new int*[r];
	    for(int i=0; i<r; i++){
	        mat[i] = new int[c];
	        for(int j=0; j<c; j++)
	            cin >> mat[i][j];
	   }

	   printSpiral(mat, 0, r-1, 0, c-1);
	   cout << endl;
	}

	return 0;
}
