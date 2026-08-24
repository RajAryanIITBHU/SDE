// Link: https://leetcode.com/problems/delete-operation-for-two-strings/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (LCS Reduction: m + n - 2 * LCS)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(m)
/*
PSEUDOCODE:
1. Compute Longest Common Subsequence (LCS) of word1 and word2.
2. Min deletions = (word1.length() - LCS) + (word2.length() - LCS) = n + m - 2 * LCS.
3. Return n + m - 2 * LCS.
*/

class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            int prev = 0;

            for (int j = 1; j <= m; j++) {
                int temp = dp[j];

                if (word1[i - 1] == word2[j - 1]) {
                    dp[j] = 1 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prev = temp;
            }
        }

        int lcs = dp[m];
        return (n - lcs) + (m - lcs);
    }
};
