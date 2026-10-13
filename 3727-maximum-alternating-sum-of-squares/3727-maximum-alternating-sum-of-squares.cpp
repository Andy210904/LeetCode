class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            if(nums[i] < 0){
                nums[i] = -nums[i];
            }
        }
        sort(nums.rbegin(),nums.rend());
        long long result = 0;
        int left = 0;
        int right = nums.size()-1;
        bool add = true;
        while(left <= right){
            if(add){
                result += (nums[left] * nums[left]);
                left++;
                add = false;
            }
            else{
                result -= (nums[right] * nums[right]);
                right--;
                add = true;
            }
            cout<<result<<endl;
        }
        return result;
    }
};