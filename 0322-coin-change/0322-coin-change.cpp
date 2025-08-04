class Solution {
public:
    int backtrack(vector<int>& coins,int ind,int target,vector<vector<int>>& dp){
        if(target == 0){
            return 0;
        }
        if(ind == 0){
            if(target % coins[ind] == 0){
                return target/coins[0];
            }
            return 1e9;
        }
        if(dp[ind][target] != -1){
            return dp[ind][target];
        }
        int notake = backtrack(coins,ind-1,target,dp);
        int take = INT_MAX;
        if(coins[ind] <= target){
            take = 1+backtrack(coins,ind,target-coins[ind],dp);
        }
        return dp[ind][target] = min(take,notake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        int res = backtrack(coins,n-1,amount,dp);
        return res >= 1e9 ? -1 : res;
    }
};