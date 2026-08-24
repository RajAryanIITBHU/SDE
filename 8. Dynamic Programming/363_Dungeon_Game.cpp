// Link: https://leetcode.com/problems/dungeon-game/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bottom-Up 1D Space-Optimized DP)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(m)
/*
PSEUDOCODE:
1. Initialize dp vector of size m + 1 with INT_MAX, dp[m - 1] = 1.
2. For i from n-1 down to 0:
     if i == n - 1: dp[m] = 1, else: dp[m] = INT_MAX
     For j from m-1 down to 0:
         minHealthNeeded = min(dp[j] (down), dp[j + 1] (right)) - dungeon[i][j]
         dp[j] = max(1, minHealthNeeded)
3. Return dp[0].
*/

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();

        vector<int> dp(m + 1, INT_MAX);
        dp[m - 1] = 1;

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int minHealth = min(dp[j], dp[j + 1]) - dungeon[i][j];
                dp[j] = max(1, minHealth);
            }
            dp[m] = INT_MAX; // Reset border for next row up
        }

        return dp[0];
    }
};
