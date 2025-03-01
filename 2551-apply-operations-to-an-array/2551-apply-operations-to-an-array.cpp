class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i] == nums[i+1]){
                nums[i] *= 2;
                nums[i+1] = 0;
            }
        }
        int left = 0;
        int right = 1;
        while(right != nums.size() && left != nums.size()){
            while(left < nums.size() && nums[left] != 0){
                left++;
                right++;
            }
            while(right < nums.size() && nums[right] == 0){
                right++;
            }
            if(left < nums.size() && right < nums.size()){
                swap(nums[left],nums[right]);
            }
        }
        return nums;
    }
};