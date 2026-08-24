// Link: https://leetcode.com/problems/longest-common-subsequence/

#include <iostream>
#include <string>
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
1. Initialize dp vector of size m + 1 with 0.
2. For i from 1 to n:
     prev = 0 (stores dp[j-1] of previous row)
     For j from 1 to m:
         temp = dp[j]
         if text1[i-1] == text2[j-1]:
             dp[j] = 1 + prev
         else:
             dp[j] = max(dp[j], dp[j-1])
         prev = temp
3. Return dp[m].
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            int prev = 0; // Represents dp[i-1][j-1]

            for (int j = 1; j <= m; j++) {
                int temp = dp[j];

                if (text1[i - 1] == text2[j - 1]) {
                    dp[j] = 1 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prev = temp;
            }
        }

        return dp[m];
    }
};
