class Solution {
public:
    bool check(vector<int>& nums) {
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());
        int n = nums.size();

        for (int x = 0; x < n; x++) { 
            bool isValid = true;
            for (int i = 0; i < n; i++) { 
                if (nums[(i + x) % n] != sortedNums[i]) { 
                    isValid = false;
                    break;
                }
            }
            if (isValid) return true;
        }

        return false;
    }
};
