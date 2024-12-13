class Solution {
public:
    long long findScore(vector<int>& nums) {
        multimap<int, int> hashMap; 
        for (int i = 0; i < nums.size(); i++) {
            hashMap.insert({nums[i], i}); 
        }
        vector<pair<int, int>> sortedMap(hashMap.begin(), hashMap.end());
        vector<bool> mark(nums.size(), false);
        long long score = 0;
        for (int i = 0; i < sortedMap.size(); i++) {
            if (!mark[sortedMap[i].second]) {
                score += sortedMap[i].first;
                if (sortedMap[i].second - 1 >= 0) {
                    mark[sortedMap[i].second - 1] = true;
                }
                if (sortedMap[i].second + 1 < nums.size()) {
                    mark[sortedMap[i].second + 1] = true;
                }
                mark[sortedMap[i].second] = true;
            }
        }
        return score;
    }
};
