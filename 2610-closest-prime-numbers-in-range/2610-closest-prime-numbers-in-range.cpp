class Solution {
public:
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false; 
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<bool>isPrime = sieve(right);
        vector<int> temp;
        for(int i = left ; i<=right;i++){
            if(isPrime[i]){
                temp.push_back(i);
            }
        }
        if(temp.size() < 2){
            return {-1,-1};
        }
        int res = INT_MAX;
        int fir = 0;
        int sec = 0;
        for(int i=0;i<temp.size()-1;i++){
            if(temp[i+1] - temp[i] < res){
                fir = temp[i];
                sec = temp[i+1];
                res = temp[i+1] - temp[i];
            }
        }
        return {fir,sec};
    }
};