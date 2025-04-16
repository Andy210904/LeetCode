class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int left = 0;
        long long cnt = 0;
        unordered_map<int, int> freq;
        long long pairs = 0;

        for (int right = 0; right < nums.size(); ++right) {
            // Add current element to the frequency map
            pairs += freq[nums[right]];
            freq[nums[right]]++;

            // Shrink the window until pairs < k
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
