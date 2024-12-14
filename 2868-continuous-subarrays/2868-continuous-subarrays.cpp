class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int left = 0;
        int right = 0;
        int maxVal = nums[0];
        int minVal = nums[0];
        long long count = 0;
        while (right < nums.size()) {
            maxVal = std::max(maxVal, nums[right]);
            minVal = std::min(minVal, nums[right]);
            if (maxVal - minVal <= 2) {
                count += (right - left + 1);
                right++;
            } else {
                left++;
                maxVal = nums[left];
                minVal = nums[left];
                for (int i = left; i <= right; ++i) {
                    maxVal = std::max(maxVal, nums[i]);
                    minVal = std::min(minVal, nums[i]);
                }
            }
        }
        return count;
    }
};
