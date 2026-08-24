/*
 * ============================================================================
 * Concept: Palindromic Dynamic Programming
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Solves subsegment palindromic DP problems.
State: `dp[i][j]` represents property (bool palindrome, max length) for substring `S[i...j]`.
Transition: `dp[i][j] = (S[i] == S[j]) && dp[i+1][j-1]`.
Iterate substring length `len` from 1 to N.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N^2) time complexity.
 * - Space Complexity: O(N^2) 2D DP matrix space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Longest Palindromic Subsequence (LC 516).
- Minimum Insertion Steps to Make a String Palindrome (LC 1312).
- Palindromic Substrings (LC 647).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Longest Palindromic Subsequence (LC 516).
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int longestPalindromeSubseq(string s) {
    int n = s.length();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int i = n - 1; i >= 0; --i) {
        dp[i][i] = 1;
        for (int j = i + 1; j < n; ++j) {
            if (s[i] == s[j]) {
                dp[i][j] = 2 + dp[i + 1][j - 1];
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][n - 1];
}

int main() {
    string s = "bbbab";
    cout << "LPS Length: " << longestPalindromeSubseq(s) << "\n"; // 4 (bbbb)
    return 0;
}
