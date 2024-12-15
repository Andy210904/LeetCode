class Solution {
public:
    void permute(vector<int>& nums,int n,vector<vector<int>>& res,vector<bool>& temp,vector<int>& temp1){
        if(temp1.size() == n){
            res.push_back(temp1);
            return;
        }
        for(int i=0;i<n;i++){
            if(!temp[i]){
                temp[i] = true;
                temp1.push_back(nums[i]);
                permute(nums,n,res,temp,temp1);
                temp[i] = false;
                temp1.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp1;
        int n = nums.size();
        vector<bool> temp(n,false);
        permute(nums,n,res,temp,temp1);
        return res;
    }
};