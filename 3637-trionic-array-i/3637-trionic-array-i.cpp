class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int ind = 1;
        if(nums[ind] < nums[ind-1]){
            return false;
        }
        while(ind < nums.size()){
            if(nums[ind] > nums[ind-1]){
                ind++;
                continue;
            }
            else{
                break;
            }
        }
        if(ind == nums.size()){
            return false;
        }
        while(ind < nums.size()){
            if(nums[ind] < nums[ind-1]){
                ind++;
                continue;
            }
            else{
                break;
            }
        }
        if(ind == nums.size()){
            return false;
        }
        while(ind < nums.size()){
            if(nums[ind] > nums[ind-1]){
                ind++;
                continue;
            }
            else{
                break;
            }
        }
        if(ind == nums.size()){
            return true;
        }
        return false;
    }
};