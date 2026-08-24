// Link: https://leetcode.com/problems/unique-paths/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Space-Optimized DP)
// ==========================================
// Time Complexity  : O(m * n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize dp vector of size n with 1 (first row paths are all 1).
2. For i from 1 to m-1:
     For j from 1 to n-1:
         dp[j] += dp[j - 1] // dp[j] is top, dp[j-1] is left
3. Return dp[n - 1].
*/

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1]; // paths from top + paths from left
            }
        }

        return dp[n - 1];
    }
};
