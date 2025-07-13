class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& image,int initial,int color,vector<int>delrow,vector<int>delcol){
        image[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int newrow = row + delrow[i];
            int newcol = col + delcol[i];
            if(newrow>=0 && newrow <n && newcol >=0 && newcol < m && image[newrow][newcol] == initial && image[newrow][newcol] != color){
                dfs(newrow,newcol,image,initial,color,delrow,delcol);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initial = image[sr][sc];
        vector<int> delrow = {-1,0,+1,0};
        vector<int> delcol = {0,+1,0,-1};
        dfs(sr,sc,image,initial,color,delrow,delcol);
        return image;
    }
};