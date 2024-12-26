class Solution {
public:
    void backtrack(vector<int>&nums,int index,int& sum,int x){
        if(index == nums.size()){
            sum += x;
            return;
        }
        backtrack(nums,index+1,sum,x);
        backtrack(nums,index+1,sum,x^nums[index]);
    }
    int subsetXORSum(vector<int>& nums) {
        int sum = 0;
        backtrack(nums,0,sum,0);
        return sum;
    }
};