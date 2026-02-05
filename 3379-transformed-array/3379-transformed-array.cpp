class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        vector<int> result = nums;
        int n = nums.size();
        int ind = 0;
        while(ind < n){
            if(nums[ind] > 0){
                result[ind] = nums[(ind + nums[ind])%n];
            }
            else if(nums[ind] < 0){
                result[ind] = nums[((ind + nums[ind]) % n + n) % n];
            }
            else{
                result[ind] = nums[ind];
            }
            ind++;
        }
        return result;
    }
};