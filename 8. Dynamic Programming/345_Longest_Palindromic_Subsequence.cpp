// Link: https://leetcode.com/problems/longest-palindromic-subsequence/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Space-Optimized Interval DP)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize dp vector of size n with 1.
2. For i from n-1 down to 0:
     prev = 0
     For j from i+1 to n-1:
         temp = dp[j]
         if s[i] == s[j]:
             dp[j] = prev + 2
         else:
             dp[j] = max(dp[j], dp[j - 1])
         prev = temp
3. Return dp[n - 1].
*/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<int> dp(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            int prev = 0; // Represents dp[i+1][j-1]

            for (int j = i + 1; j < n; j++) {
                int temp = dp[j];

                if (s[i] == s[j]) {
                    dp[j] = prev + 2;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prev = temp;
            }
        }

        return dp[n - 1];
    }
};
