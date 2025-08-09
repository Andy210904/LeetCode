class Solution {
public:
    int givesublessthanequal(vector<int>& nums, int goal) {
        if (goal < 0) return 0; 
        int l = 0, r = 0;
        int sum = 0, count = 0;
        while (r < nums.size()) {
            sum += (nums[r]%2);
            while (sum > goal && l <= r) {
                sum -= (nums[l]%2);
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return givesublessthanequal(nums, k) - givesublessthanequal(nums, k - 1);
    }
};