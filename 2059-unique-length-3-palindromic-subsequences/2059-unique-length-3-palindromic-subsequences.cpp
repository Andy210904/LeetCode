class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> alpha(26, 0);
        for (char c : s) {
            alpha[c - 'a']++;
        }
        int count = 0; 
        for (int i = 0; i < 26; i++) {
            if (alpha[i] > 1) { 
                int left = 0, right = s.size() - 1;
                unordered_set<char> temp; 
                while (s[left] != (i + 'a')) {
                    left++;
                }
                while (s[right] != (i + 'a')) {
                    right--;
                }
                for (int j = left + 1; j < right; j++) {
                    if (temp.find(s[j]) == temp.end()) { 
                        temp.insert(s[j]);
                        count++;
                    }
                }
            }
        }
        return count;
    }
};