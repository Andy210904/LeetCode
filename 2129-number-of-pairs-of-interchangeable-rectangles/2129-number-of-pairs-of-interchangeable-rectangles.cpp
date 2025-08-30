class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        long long res = 0;
        unordered_map<long double, long long> freq;
        for (auto &rect : rectangles) {
            long double ratio = (long double)rect[0] / rect[1]; 
            freq[ratio]++;
        }
        for (auto &p : freq) {
            long long k = p.second;
            res += (k * (k - 1)) / 2; // number of ways to pick 2 rectangles out of n having the same ratio.
        }
        return res;
    }
};
