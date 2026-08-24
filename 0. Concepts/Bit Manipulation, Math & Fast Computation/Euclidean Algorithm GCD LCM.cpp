/*
 * ============================================================================
 * Concept: Euclidean Algorithm (GCD & LCM)
 * Subtopic: Bit Manipulation, Math & Fast Computation
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Computes Greatest Common Divisor (GCD) using Euclidean Algorithm: `gcd(a, b) = b == 0 ? a : gcd(b, a % b)`.
Lowest Common Multiple (LCM): `lcm(a, b) = (a / gcd(a, b)) * b` (divide first to prevent integer overflow).
Standard C++ library: `std::gcd(a, b)` and `std::lcm(a, b)`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log(min(A, B))) time complexity.
 * - Space Complexity: O(1) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Simplify fractions, ratio matching, cycle period calculation.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Custom GCD and LCM implementations.
 */

#include <iostream>
#include <numeric>

using namespace std;

long long gcdCustom(long long a, long long b) {
    return b == 0 ? a : gcdCustom(b, a % b);
}

long long lcmCustom(long long a, long long b) {
    return (a / gcdCustom(a, b)) * b;
}

int main() {
    cout << "GCD(12, 18): " << gcdCustom(12, 18) << "\n"; // 6
    cout << "LCM(12, 18): " << lcmCustom(12, 18) << "\n"; // 36
    return 0;
}
