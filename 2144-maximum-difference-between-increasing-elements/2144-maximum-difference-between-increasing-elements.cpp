class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int min_ind = 0;
        int min_value = INT_MAX;
        int res = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i] <= min_value){
                min_value = nums[i];
                min_ind = i;
            }
            if(i!=min_ind){
                res = max(res,nums[i] - min_value);
            }
        }
        return res;
    }
};