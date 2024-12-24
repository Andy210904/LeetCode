class Solution {
    int diameter(unordered_map<int,vector<int>>& adj,int n){
        vector<bool> visited(n,false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        int last;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                last = q.front();
                q.pop();
                visited[last]=true;
                for(int ele: adj[last]){
                    if(!visited[ele])
                        q.push(ele);
                }
            }
        }
        q.push(last);
        int hops=0;
        vector<int> vis(n,false);
        vis[last]=true;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;++i){
                int curr = q.front();
                q.pop();
                vis[curr]=true;
                for(int ele: adj[curr]){
                    if(!vis[ele])
                        q.push(ele);
                }
            }
            hops+=1;
        }
        return hops-1;
    }
    int findDiameter(vector<vector<int>>& edges){
        if(edges.size()==0)
            return 0;
        unordered_map<int,vector<int>> adj;
        unordered_set<int> nodes;
        for(auto& edge: edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            nodes.insert(edge[0]);
            nodes.insert(edge[1]);
        }
        return diameter(adj,nodes.size());
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int dia1 = findDiameter(edges1);
        int dia2 = findDiameter(edges2);
        int radius1 = (dia1+1)/2;
        int radius2 = (dia2+1)/2;
        int sum = 1+radius1+radius2;
        return max(sum,max(dia1,dia2));
    }
};