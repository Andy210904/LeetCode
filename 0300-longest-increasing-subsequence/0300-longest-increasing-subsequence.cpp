class Solution {
public:
    int backtrack(vector<int>& nums, int ind, int prev, vector<vector<int>>& dp){
        if(ind >= nums.size()){
            return 0;
        }
        if(dp[ind][prev+1] != -1){
            return dp[ind][prev+1];
        }
        int take = 0;
        if(prev == -1 || nums[prev] < nums[ind]){
            take = 1 + backtrack(nums, ind+1, ind, dp);
        }
        int nottake = backtrack(nums, ind+1, prev, dp);
        return dp[ind][prev+1] = max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));

        return backtrack(nums, 0, -1, dp);
    }
};