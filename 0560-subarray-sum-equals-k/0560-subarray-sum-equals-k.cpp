class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> pref;
        int prefsum = 0;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefsum += nums[i];
            if (prefsum == k) {
                count++;
            }
            if (pref.find(prefsum - k) != pref.end()) {
                count+=pref[prefsum-k];
            }
            pref[prefsum]++; 
        }
        return count;
    }
};