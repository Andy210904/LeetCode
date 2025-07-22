class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& visited, vector<int>& dir_row, vector<int>& dir_col) {
        visited[row][col] = 1;
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < 4; i++) {
            int nrow = row + dir_row[i];
            int ncol = col + dir_col[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && 
                visited[nrow][ncol] == 0 && board[nrow][ncol] == 'O') {
                dfs(nrow, ncol, board, visited, dir_row, dir_col);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        if (n == 0) return;
        int m = board[0].size();
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> dir_row = {-1, 0, 1, 0};
        vector<int> dir_col = {0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O' && visited[0][i] == 0) {
                dfs(0, i, board, visited, dir_row, dir_col);
            }
            if (board[n - 1][i] == 'O' && visited[n - 1][i] == 0) {
                dfs(n - 1, i, board, visited, dir_row, dir_col);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O' && visited[i][0] == 0) {
                dfs(i, 0, board, visited, dir_row, dir_col);
            }
            if (board[i][m - 1] == 'O' && visited[i][m - 1] == 0) {
                dfs(i, m - 1, board, visited, dir_row, dir_col);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && visited[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
