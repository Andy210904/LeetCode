class Solution {
public:
    int findNumberOfLIS(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), cnt(n, 1);
        int maxLen = 1;
        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (arr[i] > arr[prev]) {
                    if (dp[prev] + 1 > dp[i]) {
                        dp[i] = dp[prev] + 1;
                        cnt[i] = cnt[prev]; 
                    } else if (dp[prev] + 1 == dp[i]) {
                        cnt[i] += cnt[prev]; 
                    }
                }
            }
            maxLen = max(maxLen, dp[i]);
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dp[i] == maxLen) {
                count += cnt[i];
            }
        }
        return count;
    }
};
