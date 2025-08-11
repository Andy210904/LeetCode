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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extra = 0;
        DisJoint ds(n);
        for(int i=0;i<connections.size();i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findUpar(u) == ds.findUpar(v)){
                extra++;
            }
            else{
                ds.unionbysize(u,v);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(ds.parent[i] == i){
                ans++;
            }
        }
        if(extra >= ans-1){
            return ans-1;
        }
        return -1;
    }
};