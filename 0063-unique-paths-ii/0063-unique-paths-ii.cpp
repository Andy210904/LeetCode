class Solution {
public:
    int findpath(int i, int j, vector<vector<int>>& dp,vector<vector<int>>& grid) {
        if(i == 0 && j == 0 && grid[i][j]!=1) return 1;
        if(i < 0 || j < 0 || grid[i][j] == 1) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int up = findpath(i - 1, j, dp,grid);
        int left = findpath(i, j - 1, dp,grid);
        return dp[i][j] = left + up;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return findpath(m-1,n-1,dp,obstacleGrid);
    }
};