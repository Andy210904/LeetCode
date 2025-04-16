class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int left = 0;
        long long cnt = 0;
        unordered_map<int, int> freq;
        long long pairs = 0;
        for (int right = 0; right < nums.size(); ++right) {
            pairs += freq[nums[right]];
            freq[nums[right]]++;
            while (pairs >= k) {
                cnt += nums.size() - right;
                freq[nums[left]]--;
                pairs -= freq[nums[left]];
                left++;
            }
        }

        return cnt;
    }
};
