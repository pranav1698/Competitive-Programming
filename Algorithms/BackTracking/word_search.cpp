// Searching a word in a crossword of words
// SlothyCoder16
// August 20, 2020

class Solution {
public:
    bool** visited;

    bool search(vector<vector<char>> &board, string word, int i, int j, int pos) {
        if(word.length() == pos) return true;

        if(i < 0 || j < 0 || i >= board.size() || j >= board[i].size() || visited[i][j] || board[i][j] != word[pos]) return false;

        visited[i][j] = true;
        if(search(board, word, i-1, j, pos+1) || search(board, word,  i, j-1, pos+1) || search(board, word, i+1, j, pos+1) || search(board, word, i, j+1, pos + 1)) return true;
        visited[i][j] = false;

        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        visited = new bool*[board.size()];
        for(int i=0; i<board.size(); i++) {
            visited[i] = new bool[board[i].size()];
            for(int j=0; j<board[i].size(); j++) visited[i][j] = false;
        }

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(word[0] == board[i][j] && search(board, word, i, j, 0)){
                    return true;
                }
            }
        }

        return false;
    }
};
