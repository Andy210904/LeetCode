class Solution {
public:
    bool isPoss(vector<vector<char>>& board,int col,int row){
        for(int i=col;i>=0;i--){
            if(board[row][i]=='Q'){
                return false;
            }
        }
        for(int i=row;i>=0;i--){
            if(board[i][col]=='Q'){
                return false;
            }
        }
        int row1 = row;
        int col1 = col;
        while(row > 0 && col > 0){
            if(board[row-1][col-1] == 'Q'){
                return false;
            }
            row--;
            col--;
        }
        while(row1 >0 && col1 < board.size()-1){
            if(board[row1-1][col1+1] == 'Q'){
                return false;
            }
            row1--;
            col1++;
        }
        return true;
    }
    void backtrack(vector<vector<char>> board,int n,int row, int& ans){
        if(row == n){
            ans++;
            return;
        }
        for(int col = 0;col<n;col++){
            if(isPoss(board,col,row)){
                board[row][col] = 'Q';
                backtrack(board,n,row+1,ans);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        vector<vector<char>> board(n,vector<char>(n,'.'));
        int ans = 0;
        backtrack(board,n,0,ans);
        return ans;
    }
};