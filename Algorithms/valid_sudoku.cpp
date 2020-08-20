// Finding if given configuration of sudoku is valid
// SlothyCoder16
// August 20, 2020

class Solution {
public:
    bool isValid(vector<vector<char>> &board, int row, int col, int curr) {
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

    bool isValidSudoku(vector<vector<char>>& board) {
        if(board.size() == 0) return false;

        char curr;
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board.size(); j++) {
                if(board[i][j] != '.') {
                    curr  = board[i][j];
                    board[i][j] = '.';
                    if(!isValid(board, i, j, curr)) return false;
                    board[i][j] = curr;
                }
            }
        }

        return true;
    }
};
