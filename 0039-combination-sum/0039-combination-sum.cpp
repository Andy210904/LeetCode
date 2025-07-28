class Solution {
public:
    void backtrack(vector<int>& candidates, int target,int sum,int ind,vector<int> temp,vector<vector<int>>& res){
        if(ind >= candidates.size() || sum > target){
            return;
        }
        
        if(sum == target){
            res.push_back(temp);
            return;
        }
        
        temp.push_back(candidates[ind]);
        backtrack(candidates,target,sum+candidates[ind],ind,temp,res);
        temp.pop_back();
        backtrack(candidates,target,sum,ind+1,temp,res);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        backtrack(candidates,target,0,0,temp,res);
        return res;
    }
};