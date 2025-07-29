class Solution {
public:
    int bfs(int sr,int sc,int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dist){
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({dist[sr][sc],{sr,sc}});
        vector<int> dr={-1,0,1,1,1,0,-1,-1};
        vector<int> dc={1,1,1,0,-1,-1,-1,0};
        while(!pq.empty()){
            int r = pq.top().second.first;
            int c = pq.top().second.second;
            int dis = pq.top().first;
            pq.pop();
            for(int i=0;i<8;i++){
                int newr = r + dr[i];
                int newc = c + dc[i];
                if(newr >= 0 && newr <n && newc >=0 && newc <m && grid[newr][newc] ==0 && dist[newr][newc] > dist[r][c] +dis){
                    dist[newr][newc] = dist[r][c]+1;
                    pq.push({dist[newr][newc],{newr,newc}}); 
                }
            }
        }
        if(dist[n-1][m-1] != INT_MAX){
            return dist[n-1][m-1]+1;
        }
        return -1;
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        if(grid[0][0] == 1){
            return -1;
        }
        dist[0][0] = 0;
        return bfs(0,0,n,m,grid,dist);
    }
};