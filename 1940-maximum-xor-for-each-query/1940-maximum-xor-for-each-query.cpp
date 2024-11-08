class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int temp = 0;
        int max1 = pow(2,maximumBit) -1;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            temp = temp ^ nums[i];
        }

        for(int i=0;i<nums.size();i++){
            ans[i]=temp ^ max1;
            temp = temp ^ nums[nums.size()-i-1];
        }
        return ans;
    }
};