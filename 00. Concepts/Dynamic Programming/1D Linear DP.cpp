/*
 * ============================================================================
 * Concept: 1D Linear Dynamic Programming
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Solves problems where state `dp[i]` depends on a constant number of previous subproblem states (e.g. `dp[i-1]`, `dp[i-2]`).
Space optimization: Reduce 1D array to a few variables (e.g. `prev1`, `prev2`).
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(1) space complexity after variable optimization.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - House Robber I & II (LC 198, 213).
- Climbing Stairs (LC 70).
- Decode Ways (LC 91).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. House Robber I (LC 198).
2. House Robber II (LC 213 - Circular array: run House Robber on `[0, N-2]` and `[1, N-1]`).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// House Robber (LC 198) - O(1) Space DP
int rob(const vector<int>& nums) {
    int prev2 = 0, prev1 = 0;
    for (int num : nums) {
        int curr = max(prev1, prev2 + num);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    cout << "Max Robbed Amount: " << rob(nums) << "\n"; // 2 + 9 + 1 = 12
    return 0;
}
