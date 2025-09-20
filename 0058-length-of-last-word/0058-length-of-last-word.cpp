class Solution {
public:
    int lengthOfLastWord(string s) {
        char delimiter = ' ';
        vector<string> words;
        string word;
        for (char c : s) {
            if (c != delimiter) {
                word += c;
            } else if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        if (!word.empty()) {
            words.push_back(word);
        }
        return words[words.size()-1].length();
    }
};