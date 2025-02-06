class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int, int> temp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int mul = nums[i] * nums[j];
                temp[mul]++;
            }
        }
        int count = 0;
        for (auto& pair : temp) {
            int freq = pair.second;
            if (freq > 1) {
                count += 8 * (freq * (freq - 1)) / 2;
            }
        }
        return count;
    }
};
