class Solution {
public:
    int subset(int ind, int sum, vector<int>& arr, vector<vector<int>>& dp) {
        if(ind == 0){
            if(sum == 0 && arr[0] == 0) return 2;
            if(sum == 0 || arr[0] == sum) return 1;
            return 0;
        }
        if(dp[ind][sum] != -1) return dp[ind][sum];

        int notTake = subset(ind-1, sum, arr, dp);
        int take = 0;
        if(arr[ind] <= sum)
            take = subset(ind-1, sum-arr[ind], arr, dp);

        return dp[ind][sum] = (take + notTake);
    }
    int perfectSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return subset(n-1, sum, arr, dp);
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int total = 0;
        for(int i=0;i<arr.size();i++){
            total += arr[i];
        }
        if(total-d < 0 || (total-d)% 2 == 1) return false;
        return perfectSum(arr,(total-d)/2);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};