/*
 * ============================================================================
 * Concept: Interval Dynamic Programming
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Computes optimal value over subsegments `[i...j]` by trying every possible split point `k` where `i <= k < j`.
State Transition: `dp[i][j] = min_{k} (dp[i][k] + dp[k+1][j] + cost(i, k, j))`.
Loop order: `len` from 2 to N, `i` from 0 to N-len, `j = i + len - 1`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N^3) time complexity.
 * - Space Complexity: O(N^2) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Matrix Chain Multiplication (MCM).
- Burst Balloons (LC 312).
- Minimum Cost Tree From Leaf Values (LC 1130).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Burst Balloons (LC 312).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxCoins(vector<int>& nums) {
    vector<int> val = {1};
    for (int x : nums) val.push_back(x);
    val.push_back(1);
    int n = val.size();

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; ++len) {
        for (int i = 0; i < n - len; ++i) {
            int j = i + len;
            for (int k = i + 1; k < j; ++k) {
                dp[i][j] = max(dp[i][j], val[i] * val[k] * val[j] + dp[i][k] + dp[k][j]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    vector<int> nums = {3, 1, 5, 8};
    cout << "Max Coins: " << maxCoins(nums) << "\n"; // 167
    return 0;
}
