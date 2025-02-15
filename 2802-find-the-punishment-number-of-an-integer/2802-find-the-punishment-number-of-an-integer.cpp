class Solution {
public:
    void backtrack(int n, int remaining, int sum, bool &res) {
        if (res) return; 
        if (remaining == 0) {
            if (sum == n) res = true;
            return;
        }
        
        int num = 0, power = 1;
        while (remaining > 0) {
            num = num + (remaining % 10) * power;
            remaining /= 10;
            power *= 10;
            if (sum + num <= n) {
                backtrack(n, remaining, sum + num, res);
            }
        }
    }

    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            int sq = i * i;
            bool res = false;
            backtrack(i, sq, 0, res);
            if (res) {
                sum += sq;
            }
        }
        return sum;
    }
};
