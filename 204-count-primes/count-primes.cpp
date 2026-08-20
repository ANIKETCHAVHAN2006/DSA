class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        // Only store odd numbers
        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        // 2 is prime
        int count = 1;

        for (int i = 3; i * i < n; i += 2) {
            if (isPrime[i]) {
                // Start from i*i
                // Increment by 2*i because we only care about odd numbers
                for (int j = i * i; j < n; j += 2 * i) {
                    isPrime[j] = false;
                }
            }
        }

        // Count remaining odd primes
        for (int i = 3; i < n; i += 2) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};