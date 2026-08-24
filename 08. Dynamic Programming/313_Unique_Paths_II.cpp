// Link: https://leetcode.com/problems/unique-paths-ii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Space-Optimized DP with Obstacles)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(m)
/*
PSEUDOCODE:
1. If obstacleGrid[0][0] == 1 return 0.
2. Initialize dp array of size m with 0, dp[0] = 1.
3. For i from 0 to n-1:
     For j from 0 to m-1:
         if obstacleGrid[i][j] == 1:
             dp[j] = 0 // Obstacle blocks all paths
         else if j > 0:
             dp[j] += dp[j - 1]
4. Return dp[m - 1].
*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();

        if (obstacleGrid[0][0] == 1 || obstacleGrid[n - 1][m - 1] == 1) {
            return 0;
        }

        vector<long long> dp(m, 0);
        dp[0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0; // Blocked by obstacle
                } else if (j > 0) {
                    dp[j] += dp[j - 1]; // Top + Left
                }
            }
        }

        return dp[m - 1];
    }
};
