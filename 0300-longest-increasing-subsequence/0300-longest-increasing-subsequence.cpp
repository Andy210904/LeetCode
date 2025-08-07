class Solution {
public:
    // int f(vector<int>&nums,int ind,int prev,vector<vector<int>>& dp){
    //     if(ind<0){
    //         return 0;
    //     }
    //     if(dp[ind][prev+1] != -1){
    //         return dp[ind][prev+1];
    //     }
    //     int nottake = f(nums,ind-1,prev,dp);
    //     int take = 0;
    //     if(prev == -1 || nums[ind] < nums[prev]){
    //         take = 1+f(nums,ind-1,ind,dp);
    //     }
    //     return dp[ind][prev+1] = max(take,nottake);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // MEMO SOLUTION 
        // int n = nums.size(); 
        // vector<vector<int>> dp(n,vector<int>(n+1,-1));
        // return f(nums,n-1,-1,dp);

        // LOGN BINARY SEARCH SOLUTION

        int n = nums.size();
        vector<int> temp;
        int len = 1;
        temp.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if(nums[i] > temp.back()){
                temp.push_back(nums[i]);
                len++;
            }
            else{
                int ind = lower_bound(temp.begin(),temp.end(),nums[i]) - temp.begin();
                temp[ind] = nums[i];
            }
        }
        return len;
    }
};