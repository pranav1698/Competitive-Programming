// Word Search 2 (TLE Solution)
// SlothyCoder16
// August 20, 2020

class Solution {
public:
    bool search(vector<vector<char>> &board, string word, vector<vector<bool>> visited, int i, int j, int pos) {
        if(word.length() == pos) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[i].size() || visited[i][j] || word[pos] != board[i][j]) return false;

        visited[i][j] = true;
        if(search(board, word, visited, i, j-1, pos+1) || search(board, word, visited, i+1, j, pos+1) || search(board, word, visited, i, j+1, pos+1) || search(board, word, visited, i-1, j, pos+1)) {
            return true;
        }
        visited[i][j] = false;

        return false;
    }

    bool findWord(vector<vector<char>> &board, string word) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));

        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++) {
                if(board[i][j] == word[0] && search(board, word, visited, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> ans;

        for(int i=0; i<words.size(); i++) {
            if(findWord(board, words[i])) {
                ans.push_back(words[i]);
            }
        }

        return ans;
    }
};
