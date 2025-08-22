class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int start_row = INT_MAX;
        int start_col = INT_MAX;
        int end_col = INT_MIN;
        int end_row = INT_MIN;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    end_row = max(end_row,i);
                    end_col = max(end_col,j);
                    start_row = min(start_row,i);
                    start_col = min(start_col,j);
                }
            }
        }
        int area = (end_row - start_row + 1)* (end_col - start_col + 1);
        return area;

    }
};