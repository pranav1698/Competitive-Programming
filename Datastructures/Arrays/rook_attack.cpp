// Attack of the rook
// SlothyCoder16
// September 20, 2020

class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int rx, ry;
        bool flag=false;
        for(rx=0; rx<board.size(); rx++) {
            for(ry=0; ry<board[0].size(); ry++) {
                if(board[rx][ry] == 'R') {
                    flag=true;
                    break;
                }
            }
            if(flag) break;
        }

        int count=0;
        for(int j=ry+1; j<board[0].size(); j++) {
            if(board[rx][j] == 'p') {
                count++;
                break;
            } else if(board[rx][j] == 'B') {
                break;
            }
        }

        for(int j=ry-1; j>=0; j--) {
            if(board[rx][j] == 'p') {
                count++;
                break;
            } else if(board[rx][j] == 'B') {
                break;
            }
        }

        for(int i=rx+1; i<board.size(); i++) {
            if(board[i][ry] == 'p') {
                count++;
                break;
            } else if(board[i][ry] == 'B') {
                break;
            }
        }

        for(int i=rx-1; i>=0; i--) {
            if(board[i][ry] == 'p') {
                count++;
                break;
            } else if(board[i][ry] == 'B') {
                break;
            }
        }

        return count;
    }
};
