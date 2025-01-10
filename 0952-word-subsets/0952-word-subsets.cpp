class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> req(26, 0);
        for (int i = 0; i < words2.size(); i++) {
            vector<int> temp(26, 0);
            for (int j = 0; j < words2[i].size(); j++) {
                temp[words2[i][j] - 'a']++;
            }
            for (int k = 0; k < 26; k++) {
                req[k] = max(req[k], temp[k]);
            }
        }
        vector<string> res;
        for (int i = 0; i < words1.size(); i++) {
            vector<int> temp(26, 0);
            for (int j = 0; j < words1[i].size(); j++) {
                temp[words1[i][j] - 'a']++;
            }
            bool isSubset = true;
            for (int k = 0; k < 26; k++) {
                if (req[k] > 0 && temp[k] < req[k]) {
                    isSubset = false;
                    break;
                }
            }
            if (isSubset) {
                res.push_back(words1[i]);
            }
        }
        return res;
    }
};
