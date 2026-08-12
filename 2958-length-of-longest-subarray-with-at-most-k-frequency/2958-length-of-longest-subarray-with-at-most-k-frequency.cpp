class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int res = 0;
        unordered_map<int,int> temp;
        while(left <= right && right < nums.size()){
            int x = nums[right];
            if(temp[x] < k){
                temp[x]++;
                right++;
            }
            else{
                temp[nums[left]]--;
                left++;
            }
            res = max(res, right-left);
        }
        return res;
    }
};