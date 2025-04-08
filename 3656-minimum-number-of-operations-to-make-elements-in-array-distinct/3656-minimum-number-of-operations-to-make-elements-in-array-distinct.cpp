class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        unordered_set<int> initialSet(nums.begin(), nums.end());
        if (initialSet.size() == nums.size()) {
            return 0;
        }

        unordered_set<int> seen;
        int count = 0;

        while (!nums.empty()) {
            for (int i = 0; i < 3 && !nums.empty(); i++) {
                nums.erase(nums.begin());
            }
            count++;
            unordered_set<int> temp(nums.begin(), nums.end());
            if (temp.size() == nums.size()) {
                break;
            }
        }
        return count;
    }
};
