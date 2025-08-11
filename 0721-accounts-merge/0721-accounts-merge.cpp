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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        DisJoint ds(n);
        unordered_map<string,int> mails_index;
        for(int i=0;i<n;i++){
            for(int j = 1;j<accounts[i].size();j++){
                if(mails_index.find(accounts[i][j]) == mails_index.end()){
                    mails_index[accounts[i][j]] = i;
                }
                else{
                    ds.unionbysize(i,mails_index[accounts[i][j]]);
                }
            }
        }
        vector<vector<string>> merge(n);
        for(auto it : mails_index){
            string mail = it.first;
            int node = ds.findUpar(it.second);
            merge[node].push_back(mail);
        }

        vector<vector<string>> res;
        for(int i=0;i<n;i++){
            if(merge[i].size() ==0) continue;
            sort(merge[i].begin(),merge[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it : merge[i]){
                temp.push_back(it);
            }
            res.push_back(temp);
        }
        return res;
    }
};