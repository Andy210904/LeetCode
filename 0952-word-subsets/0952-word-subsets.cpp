class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> req(26, 0);
        for (const string& word : words2) {
            vector<int> freq(26, 0);
            for (char c : word) {
                freq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                req[i] = max(req[i], freq[i]);
            }
        }
        vector<string> res;
        for (const string& word : words1) {
            vector<int> temp(26, 0);
            for (char c : word) {
                temp[c - 'a']++;
            }
            bool isSubset = true;
            for (int i = 0; i < 26; i++) {
                if (temp[i] < req[i]) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset) {
                res.push_back(word);
            }
        }
        return res;
    }
};
