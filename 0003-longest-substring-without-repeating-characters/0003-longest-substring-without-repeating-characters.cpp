class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> charSet; 
        int left = 0, right = 0;
        int maxlen = 0;
        while (right < s.size()) {
            if (charSet.find(s[right]) == charSet.end()) {
                charSet.insert(s[right]);
                maxlen = max(maxlen, right - left + 1);
                right++;
            } 
            else {
                charSet.erase(s[left]);
                left++;
            }
        }
        return maxlen;
    }
};
