class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> result(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){
            result[i] = nums[nums[i]];
        } 
        return result;
    }
};