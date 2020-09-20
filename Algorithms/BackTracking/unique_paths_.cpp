// Get Unique Path in the matrix following the same pattern
// SlothyCoder16
// September 20, 2020

class Solution {
public:
    int ans=0;
    void getUniquePaths(vector<vector<int>> &grid, int x, int y, int m, int n, int count, int total) {
        if(x<0 || y<0 || x>=m || y>=n || grid[x][y] == -1 || grid[x][y]==3) return;

        if(grid[x][y] == 2){
            if(total==count) ans++;
            return;
        }

        grid[x][y]=3;
        getUniquePaths(grid, x, y+1, m, n, count, total+1);
        getUniquePaths(grid, x+1, y, m, n, count, total+1);
        getUniquePaths(grid, x, y-1, m, n, count, total+1);
        getUniquePaths(grid, x-1, y, m, n, count, total+1);
        grid[x][y]=0;

        return;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startx, starty;
        int x, y;
        int count=0;
        bool flag=false;
        for(startx=0;startx<grid.size(); startx++) {
            for(starty=0;starty<grid[0].size(); starty++) {
                if(grid[startx][starty] == 1) {
                    x=startx;
                    y=starty;
                } else if(grid[startx][starty] == 0) {
                   count++;
                }
            }
        }

        getUniquePaths(grid, x, y, grid.size(), grid[0].size(), count+1, 0);
        return ans;
    }
};
