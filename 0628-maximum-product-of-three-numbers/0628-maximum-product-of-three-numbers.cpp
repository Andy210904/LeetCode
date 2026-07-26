class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(),nums.rend());
        int left;int right;
        int n = nums.size();
        left = nums[n-1]*nums[n-2]*nums[0];
        right = nums[0]*nums[1]*nums[2];
        return right > left ? right : left;
    }
};