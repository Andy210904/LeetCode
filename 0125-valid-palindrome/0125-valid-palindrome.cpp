class Solution {
public:
    bool isPalindrome(string s) {
        string s1;
        for (int i = 0; i < s.length(); i++) {
            if (isalnum(s[i])) {
                s1 += tolower(s[i]); 
            }
        }
        int length = s1.length();
        for (int i = 0; i < length / 2; i++) {
            if (s1[i] != s1[length - 1 - i]) {
                return false; 
            }
        }
        return true;
    }
};
