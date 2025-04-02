class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long max1 = LLONG_MIN; 
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                for(int k = j + 1; k < n; k++) {
                    max1 = max(max1, (long long)(nums[i] - nums[j]) * nums[k]); 
                }
            }
        }
        return max1 > 0 ? max1 : 0;
    }
};
