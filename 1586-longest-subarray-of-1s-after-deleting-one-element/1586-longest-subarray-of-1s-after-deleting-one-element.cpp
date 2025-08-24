class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero = 0;
        int left = 0;
        int right = 0;
        int n  = nums.size();
        int maxlen = 0;
        while(right < n){
            if(nums[right] != 1){
                zero++;   
            }
            if(zero > 1){
                if(nums[left] == 0){
                    zero--;
                }
                left++;
            }
            right++;
            maxlen = max(maxlen,right-left);
        }
        return maxlen-1;
    }
};