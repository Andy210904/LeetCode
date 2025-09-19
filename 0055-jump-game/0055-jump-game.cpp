class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_range = 0;
        for(int i=0;i<nums.size();i++){
            if(max_range < i){
                return false;
            }
            else{
                max_range = max(max_range,nums[i] + i);
            }
        }
        return true;
    }
};