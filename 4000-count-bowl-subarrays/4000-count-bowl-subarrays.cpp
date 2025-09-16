class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> next_greater(n, -1);
        vector<int> prev_greater(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                next_greater[i] = st.top();
            }
            st.push(i);
        }
        st = stack<int>();
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (!st.empty()) {
                prev_greater[i] = st.top();
            }
            st.push(i);
        }
        long long res = 0;
        for (int i = 0; i < n; i++) {
            if (next_greater[i] != -1 && prev_greater[i] != -1) {
                res++;
            }
        }
        return res;
    }
};
