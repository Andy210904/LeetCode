class Solution {
public:
    void combine(vector<int>& candidates, int n, int target, int index, int sum, vector<vector<int>>& res, vector<int>& temp) {
        if (sum == target) {
            res.push_back(temp);
            return;
        }
        if (index >= n || sum > target) {
            return;
        }
        temp.push_back(candidates[index]);
        combine(candidates, n, target, index, sum + candidates[index], res, temp);
        temp.pop_back();
        combine(candidates, n, target, index + 1, sum, res, temp);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = candidates.size();
        combine(candidates, n, target, 0, 0, res, temp);
        return res;
    }
};
