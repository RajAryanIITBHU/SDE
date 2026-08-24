// Link: https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Interval Matrix Dynamic Programming)
// ==========================================
// Time Complexity  : O(n^3)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. dp table of size n x n initialized to 0.
2. For len from 2 to n-1:
     For i from 1 to n - len:
         j = i + len - 1
         dp[i][j] = INT_MAX
         For k from i to j-1:
             cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]
             dp[i][j] = min(dp[i][j], cost)
3. Return dp[1][n - 1].
*/

class Solution {
public:
    int matrixMultiplication(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // len is the chain length
        for (int len = 2; len < n; len++) {
            for (int i = 1; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int k = i; k < j; k++) {
                    int cost = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                    dp[i][j] = min(dp[i][j], cost);
                }
            }
        }

        return dp[1][n - 1];
    }
};
