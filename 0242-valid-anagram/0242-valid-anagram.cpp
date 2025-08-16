class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        unordered_map<char, int> countMap;
        for (char c : s) {
            countMap[c]++;
        }
        for (char c : t) {
            countMap[c]--;
            if (countMap[c] < 0) {
                return false;
            }
        }
        return true;
    }
};