class Solution {
public:
    void dfs(int node, vector<bool>& visited, vector<int> adj[]) {
        visited[node] = true;
        for (auto it : adj[node]) {
            if (!visited[it]) {
                dfs(it, visited, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> adj[n]; 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int cnt = 0;
        vector<bool> visited(n, false); 
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                cnt++;
                dfs(i, visited, adj);
            }
        }
        return cnt;
    }
};
