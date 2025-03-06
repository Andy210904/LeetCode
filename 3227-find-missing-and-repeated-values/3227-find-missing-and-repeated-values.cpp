class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> temp(n*n + 1,0);
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                temp[grid[i][j]]++;
            }
        }
        vector<int> res;
        for(int i=1;i<n*n+1;i++){
            if(temp[i] == 2){
                res.push_back(i);
            }
        }
        for(int i=1;i<n*n+1;i++){
            if(temp[i] == 0){
                res.push_back(i);
            }
        }
        return res;
    }
};