// Link: https://leetcode.com/problems/super-egg-drop/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (DP on Moves & Eggs: Dual State Inversion)
// ==========================================
// Time Complexity  : O(k log n)
// Space Complexity : O(k)
/*
PSEUDOCODE:
Let dp[m][k] be the maximum floors we can test with m moves and k eggs.
Recurrence:
  dp[m][k] = dp[m - 1][k - 1] (egg breaks) + dp[m - 1][k] (egg survives) + 1
1. Initialize dp vector of size k + 1 with 0.
2. moves = 0.
3. While dp[k] < n:
     moves++
     For j from k down to 1:
         dp[j] = dp[j] + dp[j - 1] + 1
4. Return moves.
*/

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<int> dp(k + 1, 0);
        int moves = 0;

        // Keep incrementing moves until we can cover at least n floors
        while (dp[k] < n) {
            moves++;

            for (int j = k; j >= 1; j--) {
                dp[j] = dp[j] + dp[j - 1] + 1;
            }
        }

        return moves;
    }
};
