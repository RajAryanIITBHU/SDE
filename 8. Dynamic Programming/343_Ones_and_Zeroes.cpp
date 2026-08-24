// Link: https://leetcode.com/problems/ones-and-zeroes/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (2D 0/1 Knapsack DP)
// ==========================================
// Time Complexity  : O(strs.size() * m * n)
// Space Complexity : O(m * n)
/*
PSEUDOCODE:
1. Initialize dp matrix of size (m + 1) x (n + 1) with 0.
2. For each string str in strs:
     zeros = count of '0's, ones = count of '1's
     For i from m down to zeros:
         For j from n down to ones:
             dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1)
3. Return dp[m][n].
*/

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        for (const string& str : strs) {
            int zeros = 0, ones = 0;
            for (char c : str) {
                if (c == '0') zeros++;
                else ones++;
            }

            // 2D 0/1 Knapsack backwards traversal
            for (int i = m; i >= zeros; i--) {
                for (int j = n; j >= ones; j--) {
                    dp[i][j] = max(dp[i][j], dp[i - zeros][j - ones] + 1);
                }
            }
        }

        return dp[m][n];
    }
};
