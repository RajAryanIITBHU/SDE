// Link: https://leetcode.com/problems/distinct-subsequences/

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
1. Initialize dp vector of size m + 1 with 0, dp[0] = 1.
2. For i from 1 to n:
     For j from m down to 1:
         if s[i-1] == t[j-1]:
             dp[j] += dp[j - 1]
3. Return dp[m].
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<unsigned long long> dp(m + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                }
            }
        }

        return dp[m];
    }
};
