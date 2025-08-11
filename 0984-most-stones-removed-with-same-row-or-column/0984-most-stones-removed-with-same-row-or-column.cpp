class DisJoint{
    vector<int> parent,size;
    public:
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
    int removeStones(vector<vector<int>>& stones) {
        int maxrow = 0;
        int maxcol = 0;
        int n = stones.size();
        for(auto it : stones){
            maxrow = max(maxrow,it[0]);
            maxcol = max(maxcol,it[1]);
        }
        DisJoint ds(maxrow + 1 + maxcol + 1);
        unordered_map<int,int> connected_nodes;
        for(auto it : stones){
            int noderow = it[0];
            int nodecol = it[1] + maxrow + 1;
            ds.unionbysize(noderow,nodecol);
            connected_nodes[noderow] = 1;
            connected_nodes[nodecol] = 1;
        }
        int cnt = 0;
        for(auto it : connected_nodes){
            if(ds.findUpar(it.first) == it.first){
                cnt++;
            }
        }
        return n-cnt;
    }
};