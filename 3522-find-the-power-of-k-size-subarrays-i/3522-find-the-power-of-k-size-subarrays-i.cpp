class Solution {
public:
    int checkSubarray(const vector<int>& nums, int start, int end) {
        for (int i = start + 1; i <= end; i++) {
            if (nums[i] != nums[i-1] + 1) {
                return -1;
            }
        }
        return nums[end];
    }
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> results;
        for (int i = 0; i <= n - k; i++) {
            results.push_back(checkSubarray(nums, i, i + k - 1));
        }
        return results;
    }
};