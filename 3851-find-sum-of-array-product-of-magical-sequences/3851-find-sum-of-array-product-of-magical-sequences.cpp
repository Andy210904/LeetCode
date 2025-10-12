class Solution {
    static constexpr int MOD = 1e9 + 7;
    // Pascal's Triangle for combinations C[n][k]
    static int C[31][31]; 
    // Memoization table: dp[remainingElements][remainingSetBits][currentIndex][bitmaskFlag]
    static int dp[31][31][50][31]; 
    int totalElements, requiredSetBits, numsSize;
    // Precompute Pascal's triangle (n choose k)
    void computeCombinations() { 
        if (C[0][0] == 1) return; 
        for (int i = 1; i <= 30; i++) { 
            C[i][0] = C[i][i] = 1; 
            for (int j = 1; j <= i / 2; j++) { 
                const int val = C[i - 1][j - 1] + C[i - 1][j]; 
                C[i][j] = C[i][i - j] = val;
            } 
        }
    }
    // Recursive DP function
    int dfs(int remainingElements, int remainingSetBits, int currentIndex, unsigned int flag, vector<int>& nums) {
        int setBitsInFlag = __builtin_popcount(flag);
        // Base cases
        if (remainingElements < 0 || remainingSetBits < 0 || remainingElements + setBitsInFlag < remainingSetBits)
            return 0;
        if (remainingElements == 0)
            return (remainingSetBits == setBitsInFlag) ? 1 : 0;
        if (currentIndex >= numsSize) return 0;

        if (dp[remainingElements][remainingSetBits][currentIndex][flag] != -1)
            return dp[remainingElements][remainingSetBits][currentIndex][flag];
        long long ans = 0;
        long long powerProduct = 1;
        int currentValue = nums[currentIndex];
        // Try picking 0..remainingElements of nums[currentIndex]
        for (int pickCount = 0; pickCount <= remainingElements; pickCount++) {
            long long combinations = C[remainingElements][pickCount] * powerProduct % MOD;
            unsigned int newFlag = flag + pickCount;
            unsigned int shiftedFlag = newFlag >> 1;
            bool leastSignificantBitSet = newFlag & 1;

            ans = (ans + combinations * dfs(remainingElements - pickCount, remainingSetBits - leastSignificantBitSet, currentIndex + 1, shiftedFlag, nums)) % MOD;

            powerProduct = (powerProduct * currentValue) % MOD;
        }
        return dp[remainingElements][remainingSetBits][currentIndex][flag] = ans;
    }
public:
    int magicalSum(int m, int k, vector<int>& nums) {
        computeCombinations();
        totalElements = m;
        requiredSetBits = k;
        numsSize = nums.size();
        // Initialize memoization table
        for (int i = 0; i <= m; i++)
            for (int j = 0; j <= m; j++)
                for (int s = 0; s < numsSize; s++)
                    memset(dp[i][j][s], -1, sizeof(int) * (m + 1));
        return dfs(m, k, 0, 0, nums);
    }
};
int Solution::C[31][31] = {{0}};
int Solution::dp[31][31][50][31];
