class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> temp = board;
        int n = board.size();
        int m = board[0].size();
        vector<int> dr = {-1,-1,-1,0,1,1,1,0};
        vector<int> dc = {-1,0,1,1,1,0,-1,-1};
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                int live_cells = 0;
                for(int k=0;k<8;k++){
                    int newr = i + dr[k];
                    int newc = j + dc[k];
                    if(newr >=0 && newr < n && newc >=0 && newc < m && board[newr][newc] == 1){
                        live_cells++;
                    }
                }
                if(board[i][j] == 0){
                    if(live_cells == 3){
                        temp[i][j] = 1;
                    }
                }
                else{
                    if(live_cells < 2){
                        temp[i][j] = 0;
                    }
                    else if(live_cells == 2 || live_cells == 3){
                        temp[i][j] = 1;
                    }
                    else if (live_cells > 3){
                        temp[i][j] = 0;
                    }
                }
            }
        }
        board = temp;
    }
};