class Solution {
public:
    void backtrack(string temp, int n, vector<string>& res) {
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }
        backtrack(temp + '0', n, res); 
        backtrack(temp + '1', n, res); 
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].size();
        vector<string> res;
        backtrack("", n, res);
        for(string s : nums){
            auto it = find(res.begin(), res.end(), s);
            if (it != res.end()) {
                res.erase(it);
            }
        }
        return res[0];
    }
};
