class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long res = 1;
        int max1 = INT_MIN;
        int min1 = INT_MAX;
        for(int i=0;i<nums.size();i++){
            max1 = max(max1,nums[i]);
            min1 = min(min1,nums[i]);
        }
        res = 1LL * k*(max1-min1);
        return res;
    }
};