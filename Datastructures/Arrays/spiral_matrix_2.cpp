// Getting spiral matrix
// SlothyCoder16
// August 30, 2020

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        if(n == 0) return res;

        int top=0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int limit = pow(n, 2);

        int curr = 1;
        while(top <= bottom && left <= right) {
            for(int j=left; j<=right; j++) {
                res[top][j] = curr;
                curr++;
            }
            top++;

            for(int i=top; i<=bottom; i++) {
                res[i][right] = curr;
                curr++;
            }
            right--;

            if(top <= bottom) {
                for(int j=right; j>=left; j--) {
                    res[bottom][j] = curr;
                    curr++;
                }
                bottom--;
            }

            if(left <= right) {
                for(int i=bottom; i>=top; i--) {
                    res[i][left] = curr;
                    curr++;
                }
                left++;
            }
        }

        return res;
    }
};
