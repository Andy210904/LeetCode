class Solution {
public:
    int m, n;
    int dirs[4][2] = {{1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    vector<vector<vector<vector<int>>>> memo;
    vector<vector<int>> grid;
    int dfs(int cx, int cy, int direction, bool turn, int target) {
        int nx = cx + dirs[direction][0];
        int ny = cy + dirs[direction][1];
        if (nx < 0 || ny < 0 || nx >= m || ny >= n || grid[nx][ny] != target) {
            return 0;
        }
        if (memo[nx][ny][direction][turn] != -1) {
            return memo[nx][ny][direction][turn];
        }
        int maxStep = dfs(nx, ny, direction, turn, 2 - target);
        if (turn) {
            maxStep = max(maxStep, dfs(nx, ny, (direction + 1) % 4, false, 2 - target));
        }

        return memo[nx][ny][direction][turn] = maxStep + 1;
    }
    int lenOfVDiagonal(vector<vector<int>>& inputGrid) {
        grid = inputGrid;
        m = grid.size();
        n = grid[0].size();
        memo.assign(m, vector<vector<vector<int>>>(n, vector<vector<int>>(4, vector<int>(2, -1))));
        int res = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    for (int direction = 0; direction < 4; ++direction) {
                        res = max(res, dfs(i, j, direction, true, 2) + 1);
                    }
                }
            }
        }
        return res;
    }
};
