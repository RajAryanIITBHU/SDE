// Link: https://leetcode.com/problems/edit-distance/

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
1. Initialize dp vector of size m + 1 where dp[j] = j.
2. For i from 1 to n:
     prev = dp[0]
     dp[0] = i
     For j from 1 to m:
         temp = dp[j]
         if word1[i-1] == word2[j-1]:
             dp[j] = prev
         else:
             dp[j] = 1 + min({prev (replace), dp[j] (delete), dp[j-1] (insert)})
         prev = temp
3. Return dp[m].
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> dp(m + 1);
        for (int j = 0; j <= m; j++) {
            dp[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            int prev = dp[0];
            dp[0] = i;

            for (int j = 1; j <= m; j++) {
                int temp = dp[j];

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = prev;
                } else {
                    dp[j] = 1 + min({prev, dp[j], dp[j - 1]});
                }

                prev = temp;
            }
        }

        return dp[m];
    }
};
