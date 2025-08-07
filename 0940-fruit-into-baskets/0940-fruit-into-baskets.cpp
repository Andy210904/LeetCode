class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int left = 0;
        int right = 0;
        int maxlen = 0;
        unordered_map<int, int> picked;
        while (right < fruits.size()) {
            picked[fruits[right]]++;
            while (picked.size() > 2) {
                picked[fruits[left]]--;
                if (picked[fruits[left]] == 0) {
                    picked.erase(fruits[left]);
                }
                left++;
            }
            maxlen = max(maxlen, right - left + 1);
            right++;
        }
        return maxlen;
    }
};
