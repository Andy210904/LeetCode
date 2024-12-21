class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n - 1;
        if (n == 1) {
            return nums[0]; 
        }
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if (mid % 2 == 0) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (mid < n - 1 && nums[mid] == nums[mid + 1]) {
                if (mid % 2 == 0) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            } else {
                return nums[mid]; 
            }
        }
        return -1; 
    }
};
