class DisJoint{
    public:
    vector<int> parent,size;
        DisJoint(int n){
            parent.resize(n+1,0);
            size.resize(n+1,1);
            for(int i=0;i<n;i++){
                parent[i] = i;
            }
        }
        int findUpar(int node){
            if(parent[node] == node){
                return node;
            }
            return parent[node] = findUpar(parent[node]);
        }
        void unionbysize(int u,int v){
            int ulp_u = findUpar(u);
            int ulp_v = findUpar(v);
            if (ulp_u == ulp_v) return;
        
            if (size[ulp_u] < size[ulp_v]) {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            } else {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};
class Solution {
public:
    bool isValid(int row, int col, int n) {
        return row >= 0 && row < n && col >= 0 && col < n;
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisJoint ds(n * n);
        vector<int> dr = {-1, 0, 1, 0};
        vector<int> dc = {0, -1, 0, 1};
        // Step 1: union existing land cells
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 0) continue;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionbysize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        int mx = 0;
        // Step 2: try changing each 0 to 1 and check max size
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                unordered_set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        components.insert(ds.findUpar(newr * n + newc));
                    }
                }
                int sizeTotal = 0;
                for (auto parent : components) {
                    sizeTotal += ds.size[parent];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        // Edge case: all 1s
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUpar(cellNo)]);
        }
        return mx;
    }
};