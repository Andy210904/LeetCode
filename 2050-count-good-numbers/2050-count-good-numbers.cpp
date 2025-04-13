class Solution {
public:
    int countGoodNumbers(long long n) {
        int MOD = pow(10,9) + 7;
        long base = 4;
        long exp = n/2;
        long res = 1;
        while(exp != 0){
            if(exp % 2 == 1){
                res *= base;
            }
            base = (base*base) % MOD;
            exp = exp/2;
            res = res % MOD;
        }
        int res1 =res;
        base = 5;
        exp = (n-(n/2));
        res = 1;
        while(exp != 0){
            if(exp % 2 == 1){
                res *= base;
            }
            base = (base*base) % MOD;
            exp = exp/2;
            res = res % MOD;
        }
        return (res*res1) % MOD;

    }
};