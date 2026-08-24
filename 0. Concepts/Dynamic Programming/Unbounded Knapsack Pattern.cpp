/*
 * ============================================================================
 * Concept: Unbounded Knapsack Pattern
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Selection problem where items can be chosen UNLIMITED TIMES.
State: `dp[w]` is minimum/maximum cost or number of ways to achieve weight `w`.
Space Optimization: Iterate capacity forwards from `wt[i]` up to `W` in 1D array `dp[w]`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N * W) time complexity.
 * - Space Complexity: O(W) 1D array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Coin Change I (LC 322 - Minimum coins).
- Coin Change II (LC 518 - Total combinations).
- Combination Sum IV (LC 377 - Total permutations).
- Rod Cutting.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Coin Change I (Min coins).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for (int coin : coins) {
        for (int w = coin; w <= amount; ++w) {
            dp[w] = min(dp[w], 1 + dp[w - coin]);
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}

int main() {
    vector<int> coins = {1, 2, 5};
    cout << "Min Coins for 11: " << coinChange(coins, 11) << "\n"; // 3 (5+5+1)
    return 0;
}
