class Solution {
public:
    //memoiazation
    // int f(vector<int>& arr,int n,vector<int>&dp){
    //     if(n == 0){
    //         return dp[n] = arr[n];
    //     }
    //     if(n < 0)return 0;
    //     if(dp[n] != -1){
    //         return dp[n];
    //     }
    //     int pick = arr[n] + f(arr,n-2,dp);
    //     int notpick =f(arr,n-1,dp);
    //     return dp[n] = max(pick,notpick);
    // }
    int rob(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n+1,-1);
        dp[0] = arr[0];
        for (int i = 1; i < n; i++) {
            int pick = arr[i];
            if (i > 1) pick += dp[i - 2];
            int np = dp[i - 1];
            dp[i] = max(pick, np);
        }
        return dp[n-1];
    }
};