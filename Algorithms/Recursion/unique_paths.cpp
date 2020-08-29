// Unique Paths for given row and column
// SlothyCoder16
// August 30, 2020

class Solution {
public:
    int count = 0;

    void uniqueHelper(int i, int j, int m, int n) {
        if(i>m) return;
        if(j>n) return;
        if(i == m && j == n) {
            count++;
            return;
        }

        uniqueHelper(i+1, j, m, n);
        uniqueHelper(i, j+1, m, n);
    }

    int uniquePaths(int m, int n) {
        if(m == 1 && n == 1) return 1;
        uniqueHelper(1,0,m-1,n-1);
        uniqueHelper(0,1,m-1,n-1);

        return count;
    }
};
