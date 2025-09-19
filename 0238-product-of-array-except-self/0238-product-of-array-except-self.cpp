class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> leftpr;
        vector<int> rightpr(nums.size(), 1);
        int product=1;
        for(int i=0;i<nums.size();i++){
            if(i==0){
                leftpr.push_back(1);
            }
            else{
                product *= nums[i-1];
                leftpr.push_back(product);
            }
        }
        product=1;
        for(int i=nums.size()-1;i>=0;i--){
            if(i==nums.size()-1){
                rightpr[i]=1;
            }
            else{
                product *= nums[i+1];
                rightpr[i]=product;
            }  
        }
        for(int i=0;i<leftpr.size();i++){
            nums[i] = leftpr[i]*rightpr[i];
        }
        return nums;
    }
};