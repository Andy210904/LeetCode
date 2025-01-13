class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> mp;
        int ans = s.length();
        for(char c : s) {
            mp[c]++;
            if(mp[c] == 3) {
                ans -= 2;
                mp[c] = 1;
            }
        }
        return ans;

    }
};