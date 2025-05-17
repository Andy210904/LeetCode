class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int res = INT_MAX;
        if(n==1){
            return nums[0];
        }
        while(left <= right){
            int mid = (left + right)/2;
            if(nums[left] <= nums[mid]){
                res = min(res,nums[left]);
                left = mid+1;
            }
            else if(nums[right] >= nums[mid]){
                res = min(res,nums[mid]);
                right = mid-1;
            }
        }
        return res;
    }
};