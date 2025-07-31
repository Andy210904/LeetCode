class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n, INT_MAX));
        for(int i=0;i<edges.size();i++){
            dist[edges[i][0]][edges[i][1]] = edges[i][2];
            dist[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        int i,j,k;
        for (k = 0; k < n; k++) {
            for (i = 0; i < n; i++) {
                for (j = 0; j < n; j++) {
                    if ((dist[k][j] != INT_MAX
                            && dist[i][k] != INT_MAX) && (dist[i][j] > (dist[i][k] + dist[k][j])
                            ))
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        int min = INT_MAX;
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            int count = 0;
            for(int j=0;j<n;j++){
                if(dist[i][j] <= distanceThreshold && dist[i][j]!=INT_MAX && i!=j){
                    count++;
                }
            }
            min = std::min(min,count);
            temp.push_back({count,i});
        }
        vector<int> secondValues;
        for (const auto& p : temp) {
            if(p.first == min){
                secondValues.push_back(p.second);
                cout<< p.first<<endl;
                cout<<p.second;
            }
        }
        sort(secondValues.begin(), secondValues.end(), std::greater<int>());
        return secondValues[0];
    }
};