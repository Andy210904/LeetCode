class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int res = nums[0];
        int maxEnding = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            maxEnding = max(maxEnding + nums[i], nums[i]);
            res = max(res, maxEnding);
        }
        int res1 = nums[0];
        int minEnd = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            minEnd = min(minEnd + nums[i], nums[i]);
            res1 = min(res1, minEnd);
        }
        if(res1 < 0){
            res1 = -res1;
        }
        res = max(res,res1);
        return res;
    }
};