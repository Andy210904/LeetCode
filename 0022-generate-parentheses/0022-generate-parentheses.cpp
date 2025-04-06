class Solution {
public:
    void backtrack(int n, int open, int close, string res, vector<string>& result) {
        if (res.size() == n * 2) {
            result.push_back(res);
            return;
        }
        if (open < n)
            backtrack(n, open + 1, close, res + '(', result);
        if (close < open)
            backtrack(n, open, close + 1, res + ')', result);
    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backtrack(n, 0, 0, "", result);
        return result;
    }
};
