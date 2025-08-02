class Solution {
public:
    int minsum(int i,int j,vector<vector<int>>& matrix,int n,int m,vector<vector<int>>& dp){
        if(j<0 || j>m-1){
            return 1e9;
        }
        if(i==0){
            return matrix[i][j];
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int up = minsum(i-1,j,matrix,n,m,dp);
        int left = minsum(i-1,j-1,matrix,n,m,dp);
        int right = minsum(i-1,j+1,matrix,n,m,dp);
        return dp[i][j] = matrix[i][j] + min({up, left, right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++){
            dp[0][j] = matrix[0][j];
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int up = matrix[i][j] + dp[i-1][j];
                int left = 1e9;
                int right = 1e9;
                if(j-1>=0){
                    left = matrix[i][j] + dp[i-1][j-1];
                }
                if(j+1 < m){
                    right = matrix[i][j] + dp[i-1][j+1];
                }
                dp[i][j] = min({up,left,right}); 
            }
        }
        int min1 = 1e9;
        for(int j=0;j<m;j++){
            min1 = min(min1,dp[n-1][j]);
        }
        return min1;
    }
};