class Solution {
public:
    int backtrack(vector<int>& days, vector<int>& costs, int index, vector<int>& memo) {
        if (index >= days.size()) {
            return 0;
        }
        if (memo[index] != -1) {
            return memo[index];
        }
        int cost1 = costs[0] + backtrack(days, costs, index + 1, memo);
        int i = index;
        while (i < days.size() && days[i] < days[index] + 7) {
            i++;
        }
        int cost7 = costs[1] + backtrack(days, costs, i, memo);
        int j = index;
        while (j < days.size() && days[j] < days[index] + 30) {
            j++;
        }
        int cost30 = costs[2] + backtrack(days, costs, j, memo);
        memo[index] = min({cost1, cost7, cost30});
        return memo[index];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> memo(days.size(), -1); 
        return backtrack(days, costs, 0, memo);
    }
};
