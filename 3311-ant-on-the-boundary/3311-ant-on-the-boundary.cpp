class Solution {
public:
    int returnToBoundaryCount(vector<int>& nums){
        int cnt = 0;
        int sum = nums[0];
        for(int i=1;i<nums.size();i++){
            if(sum == 0){
                cnt++;
            }
            sum += nums[i];
        }
        if(sum == 0){
            cnt++;
        }
        return cnt;
    }
};