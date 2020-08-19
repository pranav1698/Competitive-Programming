// Count ways of placing n queens in n*n grid using Backtracking
// SlothyCoder16
// August 19, 2020

class Solution {
public:
    int ans=0;

    bool isSolve(vector<vector<bool>> &board, int row, int col, int n) {
        for(int i=0; i<n; i++) {
            if(board[row][i]) return false;
            if(board[i][col]) return false;
        }

        int i=row, j=col;
        while(i>=0 && j>=0){
            if(board[i][j]) return false;
            i--;
            j--;
        }

        i=row, j=col;
        while(i>=0 && j<n) {
            if(board[i][j]) return false;
            i--;
            j++;
        }

        i=row, j=col;
        while(i<n && j>=0) {
            if(board[i][j]) return false;
            i++;
            j--;
        }

        i=row, j=col;
        while(i<n && j<n) {
            if(board[i][j]) return false;
            i++;
            j++;
        }

        return true;
    }

    void fillBoard(vector<vector<bool>> &board, int col, int n) {
        if(col >= n) {
            ans++;
            return;
        }

        for(int row = 0; row < n; row++) {
            if(isSolve(board, row, col, n)) {
                board[row][col] = true;
                fillBoard(board, col+1, n);
                board[row][col] = false;
            }
        }

        return;
    }


    int totalNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        fillBoard(board, 0, n);

        return ans;
    }
};
