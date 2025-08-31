class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> pref(n,0);
        pref[0] = arr[0];
        for(int i=1;i<n;i++){
            pref[i] = arr[i] ^ pref[i-1];
        }
        int m = queries.size();
        vector<int> res(m,0);
        for(int i=0;i<m;i++){
            int st = queries[i][0];
            int en = queries[i][1];
            if(st == 0){
                res[i] = pref[en];
                continue;
            }
            else{
                res[i] = pref[en] ^ pref[st-1];
            }
        }
        return res;

    }
};