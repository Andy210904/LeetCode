class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            adj[u].push_back({v,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        dist[k] = 0;
        pq.push({0,k});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : adj[node]){
                int adjnode = it.first;
                int weight = it.second;
                if(dist[adjnode] > dis + weight){
                    dist[adjnode] = dis + weight;
                    pq.push({dist[adjnode],adjnode});
                }
            }
        }
        int max_time = 0;
        for(int i=1;i<=n;i++){
            if(dist[i] > max_time){
                max_time = dist[i];
            }
        }
        return max_time == INT_MAX ? -1 : max_time;
    }
};