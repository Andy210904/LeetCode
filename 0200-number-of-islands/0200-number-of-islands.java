class Solution {
    public int numIslands(char[][] grid) {
        int cnt = 0;
        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }

        }
        return cnt;

    }

    int[] di = { 1, -1, 0, 0 };
    int[] dj = { 0, 0, -1, 1 };

    void dfs(char[][] grid, int i, int j) {
        if (i < 0 || i >= grid.length || j < 0 || j >= grid[0].length || grid[i][j] == '0') {
            return;
        }
        // System.out.println(i);
        //         System.out.println(j);

        grid[i][j] = '0';
        for (int x = 0; x < 4; x++) {
            int ni = i + di[x];
            int nj = j + dj[x];
            dfs(grid, ni, nj);
        }
    }
}