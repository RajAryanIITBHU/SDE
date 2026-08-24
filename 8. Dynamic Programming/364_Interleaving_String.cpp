// Link: https://leetcode.com/problems/interleaving-string/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Space-Optimized DP)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(m)
/*
PSEUDOCODE:
1. If n + m != s3.length() return false.
2. Initialize dp vector of size m + 1 with false, dp[0] = true.
3. For j from 1 to m: dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]).
4. For i from 1 to n:
     dp[0] = dp[0] && (s1[i - 1] == s3[i - 1])
     For j from 1 to m:
         dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) || (dp[j - 1] && s2[j - 1] == s3[i + j - 1])
5. Return dp[m].
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        if (n + m != (int)s3.length()) return false;

        vector<bool> dp(m + 1, false);
        dp[0] = true;

        for (int j = 1; j <= m; j++) {
            dp[j] = dp[j - 1] && (s2[j - 1] == s3[j - 1]);
        }

        for (int i = 1; i <= n; i++) {
            dp[0] = dp[0] && (s1[i - 1] == s3[i - 1]);

            for (int j = 1; j <= m; j++) {
                dp[j] = (dp[j] && s1[i - 1] == s3[i + j - 1]) ||
                        (dp[j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }

        return dp[m];
    }
};
