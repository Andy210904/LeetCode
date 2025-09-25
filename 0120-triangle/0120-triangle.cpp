class Solution {
public:
    int minsum(vector<vector<int>>& triangle,int i,int j,int n,vector<vector<int>>& dp){
        if(i == n-1){
            return triangle[i][j];
        }
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        int same = triangle[i][j] + minsum(triangle,i+1,j,n,dp);
        int diff = triangle[i][j] + minsum(triangle,i+1,j+1,n,dp);
        return dp[i][j] = min(same,diff);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,INT_MAX));
        return minsum(triangle,0,0,n,dp);
        // for(int i=0;i<n;i++){
        //     dp[n-1][i] = triangle[n-1][i];
        // }
        // for(int i=n-2;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         int same = triangle[i][j] + dp[i+1][j];
        //         int diff = triangle[i][j] + dp[i+1][j+1];
        //         dp[i][j] = min(same,diff);
        //     }
        // }
        // return dp[0][0];
    }
};