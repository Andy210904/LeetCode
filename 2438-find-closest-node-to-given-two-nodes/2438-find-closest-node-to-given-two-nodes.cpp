class Solution {
public:
    void dfs(vector<vector<int>>& adj, int source, vector<int>& dist, int n) {
        stack<pair<int, int>> s;
        vector<bool> visited(n, false);
        s.push({source, 0});
        while (!s.empty()) {
            auto [node, d] = s.top();
            s.pop();
            if (visited[node]) continue;
            visited[node] = true;
            dist[node] = d;
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    s.push({neighbor, d + 1});
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }
        vector<int> dist1(n, -1);
        vector<int> dist2(n, -1);
        dfs(adj, node1, dist1, n);
        dfs(adj, node2, dist2, n);
        int minDist = INT_MAX;
        int result = -1;
        for (int i = 0; i < n; i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }
        return result;
    }
};
