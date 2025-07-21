class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({{i, j}, 0});
                    visited[i][j] = 2;
                }
            }
        }
        int time = 0;
        vector<int> nrow = {0, 0, -1, 1};
        vector<int> ncol = {1, -1, 0, 0};
        while (!q.empty()) {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            time = max(time, t);
            for (int i = 0; i < 4; i++) {
                int drow = r + nrow[i];
                int dcol = c + ncol[i];
                if (drow >= 0 && drow < n && dcol >= 0 && dcol < m &&
                    visited[drow][dcol] == 0 && grid[drow][dcol] == 1) {
                    visited[drow][dcol] = 2;
                    q.push({{drow, dcol}, t + 1});
                }
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] != 2) {
                    return -1;
                }
            }
        }
        return time;
    }
};
