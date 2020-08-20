// Solving Sudoku using Backtracking
// SlothyCoder16
// August 20, 2020

class Solution {
public:
    bool canPlace(vector<vector<char>> &board, int row, int col, char curr) {
        for(int i=0; i<9; i++) {
            if(board[i][col] != '.' && board[i][col] == curr) {
                return false;
            }

            if(board[row][i] != '.' && board[row][i] == curr) {
                return false;
            }

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] != '.' && board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == curr) {
                return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>> &board, int row, int col) {
        if(col >= 9) {
            if(solve(board, row + 1, 0)) return true;
            return false;
        }

        if(row >= 9) {
            return true;
        }

        if(board[row][col] != '.') {
            if(solve(board, row, col+1)) return true;
            return false;
        }

        for(int i='1'; i<='9'; i++) {
            if(canPlace(board, row, col, i)){
                board[row][col] = i;
                if(solve(board, row, col+1)) return true;
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        if(board.size() == 0){
            return;
        }

        solve(board, 0, 0);
    }
};
