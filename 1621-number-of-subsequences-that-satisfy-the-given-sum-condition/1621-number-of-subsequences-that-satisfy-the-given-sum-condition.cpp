class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        const int mod = 1000000007;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        // precompute powers of 2 modulo mod otherwise it will be slow and out of bound issues
        vector<int> power(n, 1);
        for (int i = 1; i < n; i++) {
            power[i] = (power[i - 1] * 2LL) % mod;
        }
        int left = 0, right = n - 1;
        int res = 0;
        while (left <= right) {
            if (nums[left] + nums[right] <= target) {
                res = (res + power[right - left]) % mod;
                left++;
            } else {
                right--;
            }
        }
        return res;
    }
};
