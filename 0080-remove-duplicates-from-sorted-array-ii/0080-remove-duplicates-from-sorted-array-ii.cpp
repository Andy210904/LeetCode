class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int prev = nums[0];
        int n = nums.size();
        int cnt = 1;
        int ind = 1;
        int res = 1;
        for(int i=1;i<n;i++){
            if(prev == nums[i]){
                cnt++;
            }
            else{
                cnt = 1;
            }
            prev = nums[i];
            if(cnt>2){
                continue;
            }
            else{
                nums[ind] = nums[i];
                ind++;
                res++;
            }
        }
        return res;
    }
};