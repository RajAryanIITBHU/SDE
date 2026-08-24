// Link: https://leetcode.com/problems/minimum-path-sum/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Space-Optimized DP)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(m)
/*
PSEUDOCODE:
1. Initialize dp vector of size m with INT_MAX.
2. dp[0] = 0.
3. For i from 0 to n-1:
     dp[0] += grid[i][0]
     For j from 1 to m-1:
         dp[j] = min(dp[j] (from top), dp[j - 1] (from left)) + grid[i][j]
4. Return dp[m - 1].
*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> dp(m, 0);
        dp[0] = grid[0][0];

        // Initialize first row
        for (int j = 1; j < m; j++) {
            dp[j] = dp[j - 1] + grid[0][j];
        }

        // Fill DP row by row
        for (int i = 1; i < n; i++) {
            dp[0] += grid[i][0]; // First column from top only

            for (int j = 1; j < m; j++) {
                dp[j] = min(dp[j], dp[j - 1]) + grid[i][j];
            }
        }

        return dp[m - 1];
    }
};
