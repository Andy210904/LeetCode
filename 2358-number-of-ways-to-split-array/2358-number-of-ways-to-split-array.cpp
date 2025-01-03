class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long right_sum = 0;
        long long left_sum = 0;
        for(int i=0;i<nums.size();i++){
            right_sum += nums[i];
        }
        int ind = 0;
        int count = 0;
        while(ind < nums.size()-1){
            left_sum += nums[ind];
            right_sum -= nums[ind];
            if(left_sum >= right_sum){
                count++;
            }
            ind++;
        }
        return count;
    }
};