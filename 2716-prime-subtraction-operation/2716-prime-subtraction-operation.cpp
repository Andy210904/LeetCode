class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        vector<int> primes = sieve(1000);  
        for(int i = nums.size() - 2; i >= 0; i--) {

            if(nums[i] >= nums[i + 1]) {
                int diff = nums[i] - nums[i + 1];
                int pri = findPrimeJustGreaterThan(primes, diff);
                nums[i] -= pri;
            }
        }
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i + 1] < nums[i] || nums[i] <= 0) {
                return false;
            }
        }
        return true;
    }

private:
    vector<int> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        vector<int> primes;
        for(int i = 2; i <= n; i++) {
            if(isPrime[i]) {
                primes.push_back(i);
            }
        }
        return primes;
    }
    int findPrimeJustGreaterThan(const vector<int>& primes, int limit) {
        // Find the smallest prime that is greater than the limit
        int left = 0, right = primes.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (primes[mid] > limit) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        cout<<primes[left]<<endl;
        return primes[left];
    }
};
