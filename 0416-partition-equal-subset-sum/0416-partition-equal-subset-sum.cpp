class Solution {
public:
    bool f(int ind,int target,vector<int>&arr,vector<vector<int>>& dp){
        if(target == 0){
            return true;
        }
        if(ind == 0){
            return arr[0] == target;
        }
        if(dp[ind][target]!=-1){
            return dp[ind][target];
        }
        bool nottake = f(ind-1,target,arr,dp);
        bool take = false;
        if(arr[ind] <= target){
            take = f(ind-1,target-arr[ind],arr,dp);
        }
        return dp[ind][target] = nottake || take;
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));
        return f(n-1,sum,arr,dp);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
        }
        if(sum % 2 ==0){
            return isSubsetSum(nums,sum/2);
        }
        return false;
    }
};