class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for (int n : nums) {
            freq[n]++;
        }
        int res = 0;
        for (auto& pair : freq) {
            if (k == 0) {
                if (pair.second > 1) {
                    res++;
                }
            } else {
                if (freq.find(pair.first + k) != freq.end()) {
                    res++;
                }
            }
        }
        return res;
    }
};
