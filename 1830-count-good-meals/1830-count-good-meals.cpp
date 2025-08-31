class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1000000007;
        long long res = 0;
        unordered_map<int,int> freq;
        vector<int> powers;
        for (int i = 0; i <= 21; i++) {
            powers.push_back(1 << i); 
        }
        for (int x : deliciousness) {
            for (int p : powers) {
                int complement = p - x;
                if (freq.find(complement) != freq.end()) {
                    res += freq[complement];
                    res %= MOD;
                }
            }
            freq[x]++;
        }
        return (int)res;
    }
};
