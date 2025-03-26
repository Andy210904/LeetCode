class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> temp;
        int rem = grid[0][0] % x;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                temp.push_back(grid[i][j]);
                if(grid[i][j] % x != rem){
                    return -1;
                }
            }
        }
        sort(temp.begin(),temp.end());
        int op = 0;
        int mid = temp.size()/2;
        for(int i=0;i<temp.size();i++){
            int m = (temp[mid] - temp[i])/x;
            if(m < 0){
                op += -m;
            }
            else{
                op+=m;
            }
        }
        return op;
    }
};