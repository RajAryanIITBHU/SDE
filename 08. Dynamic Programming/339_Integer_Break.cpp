// Link: https://leetcode.com/problems/integer-break/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D DP Array / Math)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize dp vector of size n + 1 with 0, dp[1] = 1.
2. For i from 2 to n:
     For j from 1 to i-1:
         dp[i] = max({dp[i], j * (i - j), j * dp[i - j]})
3. Return dp[n].
*/

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1, 0);
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                // Break into 2 parts: j and (i - j), or break (i - j) further
                dp[i] = max({dp[i], j * (i - j), j * dp[i - j]});
            }
        }

        return dp[n];
    }
};
