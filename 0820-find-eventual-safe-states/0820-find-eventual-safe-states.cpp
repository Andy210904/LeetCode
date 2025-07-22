class Solution {
public:
    bool dfs(int node, vector<vector<int>> &adj, vector<int>& visited, vector<int>& pathvis, vector<int>& check) {
        visited[node] = 1;
        pathvis[node] = 1;
        for(auto it : adj[node]) {
            if(!visited[it]) {
                if(dfs(it, adj, visited, pathvis, check)) 
                    return true;
            } else if(pathvis[it] == 1) {
                return true;
            }
        }
        pathvis[node] = 0;
        check[node] = 1;  
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N = graph.size();
        vector<int> visited(N, 0);
        vector<int> pathvis(N, 0);
        vector<int> check(N, 0);
        for(int i = 0; i < N; i++) {
            if(!visited[i]) {
                dfs(i, graph, visited, pathvis, check);
            }
        }
        vector<int> res;
        for(int i = 0; i < N; i++) {
            if(check[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
};
