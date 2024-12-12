class Solution {
public:
    void subset_sum(vector<int>& nums,int index,int n,vector<vector<int>>& res,vector<int>& temp){
        if(index == n){
            res.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        subset_sum(nums,index+1,n,res,temp);
        temp.pop_back();
        subset_sum(nums,index+1,n,res,temp);

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> temp;
        subset_sum(nums,0,n,res,temp);
        set<vector<int>> res_set(res.begin(),res.end());
        vector<vector<int>> res1(res_set.begin(), res_set.end());
        return res1;
    }
};