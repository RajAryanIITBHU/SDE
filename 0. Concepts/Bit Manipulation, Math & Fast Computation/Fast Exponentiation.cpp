/*
 * ============================================================================
 * Concept: Binary Exponentiation (Fast Pow)
 * Subtopic: Bit Manipulation, Math & Fast Computation
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Computes `x^n` in $O(\log N)$ time using divide-and-conquer binary exponentiation:
If $n$ is even: $x^n = (x^{n/2})^2$
If $n$ is odd: $x^n = x \cdot (x^{n-1})$
Handles negative powers by `n = -n` and `x = 1/x`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log N) time complexity.
 * - Space Complexity: O(1) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Pow(x, n) (LC 50).
- Super Pow (LC 372).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Pow(x, n) (LC 50).
 */

#include <iostream>

using namespace std;

double myPow(double x, int n) {
    long long N = n;
    if (N < 0) { x = 1 / x; N = -N; }

    double ans = 1.0;
    double current_product = x;

    while (N > 0) {
        if (N % 2 == 1) ans *= current_product;
        current_product *= current_product;
        N /= 2;
    }
    return ans;
}

int main() {
    cout << "2^10 = " << myPow(2.0, 10) << "\n"; // 1024
    return 0;
}
