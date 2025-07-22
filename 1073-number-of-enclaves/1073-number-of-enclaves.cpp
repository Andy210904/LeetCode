class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& board, vector<vector<int>>& visited, vector<int>& dir_row, vector<int>& dir_col,int& count) {
        visited[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + dir_row[i];
            int ncol = col + dir_col[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && visited[nrow][ncol] == 0 && board[nrow][ncol] == 1) {
                count++;
                dfs(nrow, ncol, board, visited, dir_row, dir_col,count);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> dir_row = {-1, 0, 1, 0};
        vector<int> dir_col = {0, 1, 0, -1};
        int count = 0;
        for (int i = 0; i < m; i++) {
            if (grid[0][i] == 1 && visited[0][i] == 0) {
                count++;
                dfs(0, i, grid, visited, dir_row, dir_col,count);
            }
            if (grid[n - 1][i] == 1 && visited[n - 1][i] == 0) {
                count++;
                dfs(n - 1, i, grid, visited, dir_row, dir_col,count);
            }
        }
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1 && visited[i][0] == 0) {
                count++;
                dfs(i, 0, grid, visited, dir_row, dir_col,count);
            }
            if (grid[i][m - 1] == 1 && visited[i][m - 1] == 0) {
                count++;
                dfs(i, m - 1, grid, visited, dir_row, dir_col,count);
            }
        }
        int total = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    total++;
                }
            }
        }
        return total-count;
    }
};