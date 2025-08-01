class Solution {
public:
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