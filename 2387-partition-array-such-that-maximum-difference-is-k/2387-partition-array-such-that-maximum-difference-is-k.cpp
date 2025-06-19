class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int left = 0;
        int right = 0;
        int n = nums.size();
        while(right < n){
            while(right < n && nums[right] - nums[left] <= k){
                right++;
            }
            count++;
            left = right;
        }
        return count;
    }
};