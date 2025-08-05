class Solution {
public:
    int backtrack(vector<int>& coins,int ind,int target,vector<vector<int>>& dp){
        if(target == 0){
            return 1;
        }
        if(ind == 0){
            return (target % coins[ind] ==0);
        }
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        int notake = backtrack(coins,ind-1,target,dp);
        int take = 0;
        if(coins[ind] <= target){
            take = backtrack(coins,ind,target-coins[ind],dp);
        }
        return dp[ind][target] = take+notake;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res = backtrack(coins,n-1,amount,dp);
        return res;
    }
};