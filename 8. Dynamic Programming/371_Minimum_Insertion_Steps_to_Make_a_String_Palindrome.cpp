// Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (LPS Reduction: n - LongestPalindromicSubsequence)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Compute Longest Palindromic Subsequence (LPS) of s.
2. Min insertions = s.length() - LPS(s).
3. Return n - LPS(s).
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<int> dp(n, 1);

        for (int i = n - 1; i >= 0; i--) {
            int prev = 0;

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

        int lps = dp[n - 1];
        return n - lps;
    }
};
