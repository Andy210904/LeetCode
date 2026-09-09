class Solution {
public:
    long long countCommas(long long n) {
        long long count = 0;
        if (n >= 1000) {
            count += min(n, 999999LL) - 1000 + 1;
        }
        if (n >= 1000000) {
            count += (min(n, 999999999LL) - 1000000 + 1) * 2;
        }
        if (n >= 1000000000) {
            count += (min(n, 999999999999LL) - 1000000000 + 1) * 3;
        }
        if (n >= 1000000000000LL) {
            count += (min(n, 999999999999999LL) - 1000000000000LL + 1) * 4;
        }
        if (n >= 1000000000000000LL) {
            count += (n - 1000000000000000LL + 1) * 5;
        }
        return count;
    }
};