/*
 * ============================================================================
 * Concept: Bitwise Operators & XOR Cancellation
 * Subtopic: Bit Manipulation, Math & Fast Computation
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Uses low-level bitwise operations (`&`, `|`, `^`, `~`, `<<`, `>>`).
Properties of XOR:
1. `x ^ x = 0` (Self-cancellation)
2. `x ^ 0 = x`
3. Commutative and Associative.
Used to isolate unique non-repeating numbers in $O(N)$ time and $O(1)$ space.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Single Number I (LC 136).
- Single Number III (LC 260 - Two non-repeating numbers via lowest set bit mask).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Single Number III (LC 260).
 */

#include <iostream>
#include <vector>

using namespace std;

vector<int> singleNumberIII(const vector<int>& nums) {
    long long xor_sum = 0;
    for (int num : nums) xor_sum ^= num;

    long long diff_bit = xor_sum & (-xor_sum); // Isolate lowest set bit
    int a = 0, b = 0;
    for (int num : nums) {
        if (num & diff_bit) a ^= num;
        else b ^= num;
    }
    return {a, b};
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 2, 5};
    auto res = singleNumberIII(nums);
    cout << "Unique Numbers: " << res[0] << ", " << res[1] << "\n"; // 3, 5
    return 0;
}
