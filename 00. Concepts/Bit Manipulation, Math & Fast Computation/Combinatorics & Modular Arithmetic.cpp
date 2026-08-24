/*
 * ============================================================================
 * Concept: Combinatorics & Modular Arithmetic
 * Subtopic: Bit Manipulation, Math & Fast Computation
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Computes combinations `nCr % MOD` under prime modulo (e.g. $10^9+7$).
Modular Arithmetic Rules:
- `(a + b) % M = ((a % M) + (b % M)) % M`
- `(a * b) % M = ((a % M) * (b % M)) % M`
- Modular Inverse: $a^{-1} \equiv a^{M-2} \pmod M$ using Fermat's Little Theorem.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) precomputation for factorials, O(log M) modular inverse.
 * - Space Complexity: O(N) space for factorial tables.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Unique Paths combinations $nCr$.
- Pascal's Triangle (LC 118).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Pascal's Triangle (LC 118).
 */

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generatePascal(int numRows) {
    vector<vector<int>> triangle(numRows);
    for (int i = 0; i < numRows; ++i) {
        triangle[i].resize(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }
    }
    return triangle;
}

int main() {
    auto res = generatePascal(5);
    cout << "Pascal Row 4: ";
    for (int x : res[4]) cout << x << " "; // 1 4 6 4 1
    cout << "\n";
    return 0;
}
