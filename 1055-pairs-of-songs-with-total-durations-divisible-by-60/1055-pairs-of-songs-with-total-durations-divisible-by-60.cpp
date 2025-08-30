class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> remainderCount;
        int res = 0;
        for (int t : time) {
            int r = t % 60;
            int complement = (60 - r) % 60;
            if (remainderCount.find(complement) != remainderCount.end()) {
                res += remainderCount[complement];
            }
            remainderCount[r]++;
        }
        return res;
    }
};
