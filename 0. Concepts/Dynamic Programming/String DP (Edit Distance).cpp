/*
 * ============================================================================
 * Concept: String DP & Edit Distance
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Transforms string `S1` into string `S2` using minimum operations (Insert, Delete, Replace).
State: `dp[i][j]` is min operations to transform `S1[0...i-1]` to `S2[0...j-1]`.
Transition:
If `S1[i-1] == S2[j-1]`: `dp[i][j] = dp[i-1][j-1]`
Else: `1 + min({dp[i-1][j] (delete), dp[i][j-1] (insert), dp[i-1][j-1] (replace)})`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(M * N) time complexity.
 * - Space Complexity: O(N) space complexity using 1D rolling array.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Edit Distance (LC 72).
- Delete Operation for Two Strings (LC 583).
- Distinct Subsequences (LC 115).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Edit Distance (LC 72).
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int minDistance(string word1, string word2) {
    int m = word1.length(), n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int j = 0; j <= n; ++j) dp[0][j] = j;

    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }
    return dp[m][n];
}

int main() {
    cout << "Edit Distance (horse -> ros): " << minDistance("horse", "ros") << "\n"; // 3
    return 0;
}
