class Solution {
public:
    int givesublessthanequal(vector<int>& nums, int goal) {
        if (goal < 0) return 0; 
        int l = 0, r = 0;
        int sum = 0, count = 0;
        while (r < nums.size()) {
            sum += nums[r];
            while (sum > goal && l <= r) {
                sum -= nums[l];
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return givesublessthanequal(nums, goal) - givesublessthanequal(nums, goal - 1);
    }
};
