// Link: https://leetcode.com/problems/count-primes/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sieve of Eratosthenes)
// ==========================================
// Time Complexity  : O(n log log n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If n <= 2 return 0.
2. Initialize isPrime boolean vector of size n with true.
3. isPrime[0] = isPrime[1] = false.
4. For p from 2 such that p * p < n:
     if isPrime[p]:
         For i from p * p to n - 1 with step p:
             isPrime[i] = false
5. Count true values in isPrime array.
6. Return count.
*/

class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> isPrime(n, true);
        isPrime[0] = isPrime[1] = false;

        for (int p = 2; p * p < n; p++) {
            if (isPrime[p]) {
                for (int i = p * p; i < n; i += p) {
                    isPrime[i] = false;
                }
            }
        }

        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) count++;
        }

        return count;
    }
};
