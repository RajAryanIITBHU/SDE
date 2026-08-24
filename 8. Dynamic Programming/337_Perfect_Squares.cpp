// Link: https://leetcode.com/problems/perfect-squares/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D DP Array - Unbounded Knapsack)
// ==========================================
// Time Complexity  : O(n * sqrt(n))
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize dp vector of size n + 1 with INT_MAX, dp[0] = 0.
2. For i from 1 to n:
     For j from 1 such that j*j <= i:
         dp[i] = min(dp[i], dp[i - j * j] + 1)
3. Return dp[n].
*/

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                dp[i] = min(dp[i], dp[i - j * j] + 1);
            }
        }

        return dp[n];
    }
};
