class Solution {
public:
    unordered_set<string> temp;
    void backtrack(string res, int n) {
        if (res.size() == n) {
            temp.insert(res);
            return;
        }
        if (res.empty() || res.back() != 'a') {
            backtrack(res + "a", n);
        }
        if (res.empty() || res.back() != 'b') {
            backtrack(res + "b", n);
        }
        if (res.empty() || res.back() != 'c') {
            backtrack(res + "c", n);
        }
    }
    string getHappyString(int n, int k) {
        backtrack("", n);
        vector<string> sortedStrings(temp.begin(), temp.end());
        sort(sortedStrings.begin(), sortedStrings.end());
        if (k > sortedStrings.size()) {
            return "";
        }
        return sortedStrings[k - 1];
    }
};