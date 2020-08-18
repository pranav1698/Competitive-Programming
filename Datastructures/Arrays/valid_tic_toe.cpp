// Finding valid tic tac toe state
// SlothyCoder16
// August 18, 2020

class Solution {
public:
    bool hasWon(vector<string> &board, char chance) {
        if(board[0][0] == chance && board[0][0] == board[1][1] && board[2][2] == board[1][1]) return true;
        if(board[0][2] == chance && board[0][2] == board[1][1] && board[2][0] == board[1][1]) return true;

        for(int i=0; i<3; i++) {
            if(board[i][0] == chance && board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
            if(board[0][i] == chance && board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
        }

        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        int numX = 0;
        int numY = 0;

        for(int i=0; i<3; i++) {
            for(int j=0; j<3; j++) {
                if(board[i][j] == 'X') {
                    numX++;
                } else if(board[i][j] == 'O') {
                    numY++;
                }
            }
        }

        if(numX < numY || (numX - numY) > 1)
            return false;

        if(numX == numY) {
            if(hasWon(board, 'X')) return false;
        }

        if((numX - numY) == 1)
            if(hasWon(board, 'O')) return false;

        return true;
    }
};
