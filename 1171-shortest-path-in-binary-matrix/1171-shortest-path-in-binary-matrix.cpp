class Solution {
public:
    int bfs(int sr, int sc, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dist) {
        queue<pair<int, int>> q;
        q.push({sr, sc});
        vector<int> dr = {-1, 0, 1, 1, 1, 0, -1, -1};
        vector<int> dc = {1, 1, 1, 0, -1, -1, -1, 0};
        while (!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < 8; i++) {
                int newr = r + dr[i];
                int newc = c + dc[i];
                if (newr >= 0 && newr < n && newc >= 0 && newc < m &&
                    grid[newr][newc] == 0 && dist[newr][newc] > dist[r][c] + 1) {
                    dist[newr][newc] = dist[r][c] + 1;
                    q.push({newr, newc});
                }
            }
        }
        if (dist[n - 1][m - 1] != INT_MAX) {
            return dist[n - 1][m - 1] + 1;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        if (grid[0][0] == 1) {
            return -1;
        }
        dist[0][0] = 0;
        return bfs(0, 0, n, m, grid, dist);
    }
};
