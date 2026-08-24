/*
 * ============================================================================
 * Concept: Grid Dynamic Programming
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Computes path optimal values or total path counts in a 2D matrix.
State: `dp[r][c]` represents optimal cost or number of ways to reach cell `(r, c)` from `(0, 0)`.
Transition: `dp[r][c] = cell_val + min/max(dp[r-1][c], dp[r][c-1])`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(R * C) time complexity.
 * - Space Complexity: O(C) space complexity using 1D DP array optimization.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Unique Paths I & II (LC 62, 63).
- Minimum Path Sum (LC 64).
- Maximal Square (LC 221).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Minimum Path Sum (LC 64).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    vector<int> dp(cols, 0);

    dp[0] = grid[0][0];
    for (int c = 1; c < cols; ++c) dp[c] = dp[c - 1] + grid[0][c];

    for (int r = 1; r < rows; ++r) {
        dp[0] += grid[r][0];
        for (int c = 1; c < cols; ++c) {
            dp[c] = grid[r][c] + min(dp[c], dp[c - 1]);
        }
    }
    return dp[cols - 1];
}

int main() {
    vector<vector<int>> grid = {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    cout << "Min Path Sum: " << minPathSum(grid) << "\n"; // 7
    return 0;
}
