class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> temp(banned.begin(), banned.end()); 
        int sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (temp.find(i) != temp.end()) { 
                continue;
            }
            if (sum + i <= maxSum) {
                sum += i;
                count++;
            } else {
                break;
            }
        }
        return count;
    }
};
