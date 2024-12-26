class Solution {
public:
    void backtrack(vector<int>& nums, int index, int target, int sum, int& count) {
        if (index == nums.size()) {
            if (sum == target) {
                count++;
            }
            return;
        }
        backtrack(nums, index + 1, target, sum + nums[index], count);
        backtrack(nums, index + 1, target, sum - nums[index], count);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        backtrack(nums, 0, target, 0, count);
        return count;
    }
};
