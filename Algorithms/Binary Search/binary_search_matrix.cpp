// Binary Search in  a Matrix
// SlothyCoder16
// July 11, 2020

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i=0; i<matrix.size(); i++){
            int min = 0;
            int max = matrix[i].size() - 1;
            while(max >= min) {
                int guess = min + (max - min) / 2;
                if(matrix[i][guess] > target) {
                    max = guess - 1;
                } else if(matrix[i][guess] < target) {
                    min = guess + 1;
                } else {
                    return true;
                }
            }
        }

        return false;
    }
};
