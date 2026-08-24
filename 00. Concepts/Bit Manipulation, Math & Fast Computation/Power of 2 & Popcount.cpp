/*
 * ============================================================================
 * Concept: Power of 2 & Bit Population Count
 * Subtopic: Bit Manipulation, Math & Fast Computation
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * 1. Power of 2 Check: A positive integer `N` is a power of 2 if `(N > 0) && ((N & (N - 1)) == 0)`.
2. Bit Counting (Popcount): Counts total number of set 1-bits using Brian Kernighan's algorithm `x &= (x - 1)` or C++ built-in `__builtin_popcount(x)`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(Set Bits) or O(1) built-in.
 * - Space Complexity: O(1) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Power of Two (LC 231).
- Number of 1 Bits (LC 191).
- Counting Bits (LC 338 - DP transition: `dp[i] = dp[i >> 1] + (i & 1)`).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Counting Bits (LC 338).
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> countBits(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i >> 1] + (i & 1);
    }
    return dp;
}

int main() {
    auto res = countBits(5);
    cout << "Bit counts [0..5]: ";
    for (int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
