class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1;
        int right = *max_element(quantities.begin(), quantities.end());
        int ans = right;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int stores = 0;
            for (int quantity : quantities) {
                stores += (quantity + mid - 1) / mid;  
            }
            if (stores <= n) {
                ans = mid;  
                right = mid - 1;
            } else {
                left = mid + 1; 
            }
        }
        return ans;
    }
};
