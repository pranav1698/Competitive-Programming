// Placing n queens in n*n grid using Backtracking
// SlothyCoder16
// August 19, 2020

class Solution {
public:
    vector<vector<string>> ans;

    void makeAns(vector<vector<bool>> &board, int n) {
        vector<string> temp;
        for(int i=0; i<n; i++){
            string s = "";
            for(int j=0; j<n; j++) {
                if(board[i][j]){
                    s = s + 'Q';
                } else {
                    s = s + '.';
                }
            }
            temp.push_back(s);
        }

        ans.push_back(temp);
    }

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
            makeAns(board, n);
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


    vector<vector<string>> solveNQueens(int n) {
        vector<vector<bool>> board(n, vector<bool>(n, false));
        fillBoard(board, 0, n);

        return ans;
    }
};
