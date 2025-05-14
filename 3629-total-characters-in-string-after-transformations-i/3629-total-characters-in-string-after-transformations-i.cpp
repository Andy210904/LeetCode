class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        const int MOD = 1e9 + 7;
        vector<long long> alpha(26, 0);
        for (int i = 0; i < s.size(); i++) {
            alpha[s[i] - 'a']++;
        }
        for (int i = 0; i < t; i++) {
            vector<long long> new_alpha(26, 0);
            for (int j = 0; j < 25; j++) {
                new_alpha[j + 1] = (new_alpha[j + 1] + alpha[j]) % MOD;
            }
            new_alpha[0] = (new_alpha[0] + alpha[25]) % MOD;
            new_alpha[1] = (new_alpha[1] + alpha[25]) % MOD;
            alpha = new_alpha;
        }
        long long count = 0;
        for (int i = 0; i < 26; i++) {
            count = (count + alpha[i]) % MOD;
        }
        return (int)count;
    }
};
