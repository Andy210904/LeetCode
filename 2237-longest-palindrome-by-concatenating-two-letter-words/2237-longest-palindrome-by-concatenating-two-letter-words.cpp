class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> temp;
        int res = 0;
        for (const auto& word : words) {
            temp[word]++;
        }
        bool usedCenter = false;
        for (const auto& [word, count] : temp) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (word != rev) {
                if (temp.find(rev) != temp.end()) {
                    int pairs = min(temp[word], temp[rev]);
                    res += pairs * 4;
                    temp[word] -= pairs;
                    temp[rev] -= pairs;
                }
            } else {
                int pairs = temp[word] / 2;
                res += pairs * 4;
                temp[word] -= pairs * 2;
                if (!usedCenter && temp[word] > 0) {
                    res += 2;
                    usedCenter = true;
                }
            }
        }
        return res;
    }
};
