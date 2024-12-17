class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }
        string res = "";
        int curr = 25; 
        int next = 25;
        while (curr >= 0) {
            int rep = repeatLimit;
            while (rep > 0 && freq[curr] > 0) {
                res += (curr + 'a');
                rep--;
                freq[curr]--;
            }
            if (freq[curr] > 0) {
                next = -1;
                for (int j = curr - 1; j >= 0; j--) {
                    if (freq[j] > 0) {
                        next = j;
                        break;
                    }
                }
                if (next == -1) {
                    break;
                }
                res += (next + 'a');
                freq[next]--;
            } else {
                curr--;
            }
        }
        return res;
    }
};
