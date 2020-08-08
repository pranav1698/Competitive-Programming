// Sort the diagonals of the matrix
// SlothyCoder16
// August 08, 2020

class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        vector<vector<int>> pos;
        int c_size = mat[0].size();
        int r_size = mat.size();

        int col = 0;
        while(col<c_size) {
            vector<int> aux;
            int j = col;
            int i = 0;
            while(i<r_size && j<c_size) {
                aux.push_back(mat[i][j]);
                i++;
                j++;
            }
            pos.push_back(aux);
            col++;
        }

        int row = 1;
        while(row < r_size) {
            vector<int> aux;
            int i= row;
            int j = 0;
            while(i<r_size && j<c_size) {
                aux.push_back(mat[i][j]);
                i++;
                j++;
            }
            pos.push_back(aux);
            row++;
        }

        for(int i=0; i<pos.size(); i++) {
            sort(pos[i].begin(), pos[i].end());
        }

        col=0;
        while(col<c_size){
            int i=0;
            int j=col;
            while(i<r_size && j<c_size) {
                mat[i][j] = pos[col][i];
                i++;
                j++;
            }
            col++;
        }

        row=1;
        while(row < r_size) {
            int i= row;
            int j = 0;
            while(i<r_size && j<c_size) {
                mat[i][j] = pos[(c_size + row) - 1][j];
                i++;
                j++;
            }
            row++;
        }


        return mat;
    }
};
