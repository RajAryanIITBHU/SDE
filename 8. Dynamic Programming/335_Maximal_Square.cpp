// Link: https://leetcode.com/problems/maximal-square/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Space-Optimized DP)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(m)
/*
PSEUDOCODE:
1. Initialize dp vector of size m + 1 with 0, maxSide = 0.
2. For i from 1 to n:
     prev = 0
     For j from 1 to m:
         temp = dp[j]
         if matrix[i-1][j-1] == '1':
             dp[j] = min({dp[j] (top), dp[j-1] (left), prev (top-left)}) + 1
             maxSide = max(maxSide, dp[j])
         else:
             dp[j] = 0
         prev = temp
3. Return maxSide * maxSide.
*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> dp(m + 1, 0);
        int maxSide = 0;
        int prev = 0;

        for (int i = 1; i <= n; i++) {
            prev = 0;

            for (int j = 1; j <= m; j++) {
                int temp = dp[j];

                if (matrix[i - 1][j - 1] == '1') {
                    dp[j] = min({dp[j], dp[j - 1], prev}) + 1;
                    maxSide = max(maxSide, dp[j]);
                } else {
                    dp[j] = 0;
                }

                prev = temp;
            }
        }

        return maxSide * maxSide;
    }
};
