class Solution {
public:
    int timer = 0;
    void dfs(int n, int node, int parent, vector<int> adj[],vector<int>& ins_time, vector<int>& low_time,vector<int>& visited, vector<vector<int>>& bridges) {
        visited[node] = 1;
        ins_time[node] = low_time[node] = timer++;
        for (auto it : adj[node]) {
            if (it == parent) continue; 
            if (!visited[it]) {
                dfs(n, it, node, adj, ins_time, low_time, visited, bridges);
                low_time[node] = min(low_time[node], low_time[it]);
                //Bridge
                if (low_time[it] > ins_time[node]) {
                    bridges.push_back({node, it});
                }
            }
            else {
                // Back edge
                low_time[node] = min(low_time[node], ins_time[it]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        for (auto& it : connections) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> ins_time(n, -1), low_time(n, -1), visited(n, 0);
        vector<vector<int>> bridges;
        //for disconnected graph
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(n, i, -1, adj, ins_time, low_time, visited, bridges);
            }
        }
        return bridges;
    }
};
