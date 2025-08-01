class Solution {
public:
    bool dfs(int node,int col ,vector<int>& color,vector<vector<int>>& adj){
        color[node] = col;
        for(auto it : adj[node]){
            if(color[it] == -1){
                if(dfs(it,!col,color,adj) == false) return false;
            }
            else if(color[it] == col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        int m = graph[0].size();
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i] == -1){
                if(dfs(i,0,color,graph) == false) return false;
            }
        }
        return true;
    }
};