class Solution {
public:
    int minsum(vector<vector<int>>& grid,int row,int col,vector<vector<int>>& dp){
        if(row==0 && col == 0){
            return grid[row][col];
        }
        if(row < 0 || col < 0){
            return INT_MAX;
        }
        if(dp[row][col] != -1){
            return dp[row][col];
        }
        int left = minsum(grid,row,col-1,dp);
        int up = minsum(grid,row-1,col,dp);
        return dp[row][col] = grid[row][col]+min(left,up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col,-1));
        return minsum(grid,row-1,col-1,dp);
    }
};