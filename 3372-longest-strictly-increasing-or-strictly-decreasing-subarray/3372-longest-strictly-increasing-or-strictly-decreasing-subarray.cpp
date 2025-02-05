class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int max = 1;
        int s_inc = 1;
        int s_dec = 1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] > nums[i-1]){
                s_inc++;
            }
            else{
                s_inc = 1;
            }
            max = std::max(max,s_inc);
        }
        for(int i=1;i<nums.size();i++){
            if(nums[i] < nums[i-1]){
                s_dec++;
            }
            else{
                s_dec = 1;
            }
            max = std::max(max,s_dec);
        }
        return max;
    }
};