class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> temp;
        int left = 0;
        int right = 0;
        int maxlen = 0;
        int len = 0;
        while(right < s.size()){
            if(temp.find(s[right]) == temp.end()){
                temp.insert(s[right]);
                right++;
                len++;
            }
            else{
                temp.erase(s[left]);
                left++;
                len--;
            }
            maxlen = max(maxlen,len);
        }
        return maxlen;
    }
};