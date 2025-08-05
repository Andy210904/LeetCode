class Solution {
public:
    int backtrack(vector<int>& nums,int ind,int target){
        if(ind == 0){
            return (nums[0] == target) + (nums[0] == -target);
        }
        int add = backtrack(nums,ind-1,target-nums[ind]);
        int sub = backtrack(nums,ind-1,target+nums[ind]);
        return add+sub;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return backtrack(nums,n-1,target);
    }
};