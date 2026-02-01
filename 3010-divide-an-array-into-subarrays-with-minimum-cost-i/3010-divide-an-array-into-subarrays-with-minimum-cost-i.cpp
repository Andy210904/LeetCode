class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size() == 3){
            return  nums[0]+nums[1]+nums[2];
        }
        int sum = nums[0];
        int num1 = INT_MAX;
        int ind = -1;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < num1){
                num1 = nums[i];
                ind = i;
            }
        }
        int num2 = INT_MAX;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < num2 && i != ind){
                num2 = nums[i];
            }
        }
        return sum + num1 + num2;
    }
};