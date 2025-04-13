class Solution {
public:
    const int MOD = 1e9 + 7;
    long long power(long long base, long long exp) {
        long long result = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }
    int countGoodNumbers(long long n) {
        long long evenPositions = n / 2;
        long long oddPositions = n - evenPositions;
        long long evenPow = power(5, oddPositions); 
        long long oddPow = power(4, evenPositions);
        return (evenPow * oddPow) % MOD;
    }
};
