// Find unique paths depending on the obstacles grid
// SlothyCoder16
// August 30, 2020

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        if(obstacleGrid[0][0] == 1) return 0;
        dp[0][0] = 1;

        for(int j=1; j<obstacleGrid[0].size(); j++)
            if(obstacleGrid[0][j] == 0)
                dp[0][j] = dp[0][j-1];
        for(int i=1; i<obstacleGrid.size(); i++)
            if(obstacleGrid[i][0] == 0)
                dp[i][0] = dp[i-1][0];

        for(int i=1; i<obstacleGrid.size(); i++){
            for(int j=1; j<obstacleGrid[0].size(); j++){
                if(obstacleGrid[i][j] == 0) {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }

        return dp[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};
