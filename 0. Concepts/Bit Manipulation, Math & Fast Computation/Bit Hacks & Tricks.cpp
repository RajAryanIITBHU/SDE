/*
 * ============================================================================
 * Concept: Bit Hacks & Manipulation Tricks
 * Subtopic: Bit Manipulation, Math & Fast Computation
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Essential bit manipulation tricks:
1. Clear lowest set bit: `x & (x - 1)`
2. Extract lowest set bit: `x & (-x)`
3. Swap two integers without temp variable: `a ^= b; b ^= a; a ^= b;`
4. Set k-th bit: `x | (1 << k)`
5. Clear k-th bit: `x & ~(1 << k)`
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(1) time complexity.
 * - Space Complexity: O(1) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Bitwise algorithms and fast optimizations.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Bit manipulation utilities demonstration.
 */

#include <iostream>

using namespace std;

int main() {
    int x = 12; // Binary: 1100
    cout << "Clear lowest set bit of 12: " << (x & (x - 1)) << "\n"; // 8 (1000)
    cout << "Extract lowest set bit of 12: " << (x & (-x)) << "\n";  // 4 (0100)
    return 0;
}
