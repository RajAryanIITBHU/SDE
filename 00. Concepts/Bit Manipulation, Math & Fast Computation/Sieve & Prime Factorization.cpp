/*
 * ============================================================================
 * Concept: Sieve of Eratosthenes & Prime Factorization
 * Subtopic: Bit Manipulation, Math & Fast Computation
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Sieve of Eratosthenes finds all prime numbers up to `N` in $O(N \log \log N)$ time by iteratively marking multiples of prime numbers starting from 2 as composite.
Prime Factorization breaks a number into product of prime factors.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N log log N) build time, O(sqrt(N)) single number prime factorize.
 * - Space Complexity: O(N) boolean array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Count Primes (LC 204).
- Prime Factorization tasks.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Sieve of Eratosthenes (LC 204).
 */

#include <iostream>
#include <vector>

using namespace std;

int countPrimes(int n) {
    if (n <= 2) return 0;
    vector<bool> isPrime(n, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j += i) isPrime[j] = false;
        }
    }
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if (isPrime[i]) count++;
    }
    return count;
}

int main() {
    cout << "Primes < 10: " << countPrimes(10) << "\n"; // 4 (2, 3, 5, 7)
    return 0;
}
