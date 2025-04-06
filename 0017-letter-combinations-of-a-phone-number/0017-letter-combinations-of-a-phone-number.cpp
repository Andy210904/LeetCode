class Solution {
public:
    void backtrack(const string& digits, unordered_map<char, string>& temp, string res, int index, vector<string>& result) {
        if (index == digits.size()) {
            result.push_back(res);
            return;
        }
        string possible = temp[digits[index]];
        for (char c : possible) {
            backtrack(digits, temp, res + c, index + 1, result);
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        unordered_map<char, string> temp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> result;
        backtrack(digits, temp, "", 0, result);
        return result;
    }
};
