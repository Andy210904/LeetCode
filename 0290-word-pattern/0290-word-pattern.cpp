class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> pattern_s;
        unordered_map<string, char> s_pattern;
        istringstream iss(s);
        vector<string> words;
        string word;
        while (iss >> word) {
            words.push_back(word);
        }
        if (words.size() != pattern.size()) {
            return false;
        }
        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];
            if (pattern_s.find(c) != pattern_s.end()) {
                if (pattern_s[c] != w) return false;
            } else {
                pattern_s[c] = w;
            }
            if (s_pattern.find(w) != s_pattern.end()) {
                if (s_pattern[w] != c) return false;
            } else {
                s_pattern[w] = c;
            }
        }
        return true;
    }
};
