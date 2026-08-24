/*
 * ============================================================================
 * Concept: 0-1 Knapsack Pattern
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Selection problem where each item can be chosen AT MOST ONCE (0 or 1).
State: `dp[i][w]` is max value using a subset of first `i` items with capacity `w`.
Transition: `dp[i][w] = max(dp[i-1][w], val[i] + dp[i-1][w - wt[i]])`.
Space Optimization: Iterate capacity backwards from `W` down to `wt[i]` in 1D array `dp[w]`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N * W) time complexity.
 * - Space Complexity: O(W) space complexity using 1D reverse iteration.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Subset Sum Problem.
- Partition Equal Subset Sum (LC 416).
- Target Sum (LC 494).
- Last Stone Weight II (LC 1049).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Partition Equal Subset Sum (LC 416).
 */

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

bool canPartition(vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;
    int target = sum / 2;

    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int w = target; w >= num; --w) {
            dp[w] = dp[w] || dp[w - num];
        }
    }
    return dp[target];
}

int main() {
    vector<int> nums = {1, 5, 11, 5};
    cout << "Can Partition: " << (canPartition(nums) ? "Yes" : "No") << "\n";
    return 0;
}
