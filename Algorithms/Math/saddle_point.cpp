// Saddle point in a matrix
// SlothyCoder16
// August 28, 2020

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int mat[n][n];

  bool flag = false;
  for(int i=0; i<n; i++) {
    for(int j=0; j<n; j++) {
      cin >> mat[i][j];
    }
  }

  for(int i=0; i<n; i++) {
    int row_min = INT_MAX;
    int col_index = 0;
    for(int j=0; j<n; j++) {
      if(mat[i][j] < row_min) {
        row_min = mat[i][j];
        col_index = j;
      }
    }

    int k;
    for(k=0; k<n; k++) {
      if(row_min < mat[k][col_index]) {
        break;
      }
    }

    if(k == n) {
        cout << row_min << endl;
        return 0;
    }

    flag = true;
  }


  if(flag) cout << "No Saddle Point" << endl;
}
