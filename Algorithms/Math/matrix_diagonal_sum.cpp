// Matrix Diagonal Sum for a Matrix
// SlothyCoder16
// September 15, 2020

class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        int sum=0;
        int i=0, j=0;
        while(i<m && j<n) {
            sum += mat[i][j];
            i++;
            j++;
        }

        i=0;
        j=n-1;
        while(i<m && j>=0) {
            if(!visited[i][j]) sum+=mat[i][j];
            i++;
            j--;
        }

        return sum;
    }
};
