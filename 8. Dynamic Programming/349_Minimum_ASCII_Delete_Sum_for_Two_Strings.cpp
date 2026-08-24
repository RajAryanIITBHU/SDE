// Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

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
1. Initialize dp vector of size m + 1 where dp[j] = sum of ASCII values of s2[0..j-1].
2. For i from 1 to n:
     prev = dp[0]
     dp[0] += s1[i - 1]
     For j from 1 to m:
         temp = dp[j]
         if s1[i-1] == s2[j-1]:
             dp[j] = prev
         else:
             dp[j] = min(dp[j] + s1[i-1], dp[j-1] + s2[j-1])
         prev = temp
3. Return dp[m].
*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        vector<int> dp(m + 1, 0);
        for (int j = 1; j <= m; j++) {
            dp[j] = dp[j - 1] + s2[j - 1];
        }

        for (int i = 1; i <= n; i++) {
            int prev = dp[0];
            dp[0] += s1[i - 1];

            for (int j = 1; j <= m; j++) {
                int temp = dp[j];

                if (s1[i - 1] == s2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = min(dp[j] + s1[i - 1], dp[j - 1] + s2[j - 1]);
                }

                prev = temp;
            }
        }

        return dp[m];
    }
};
