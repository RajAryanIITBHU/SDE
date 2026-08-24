// Link: https://leetcode.com/problems/allocate-mailboxes/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sorting + Median Cost Precomputation + 2D DP)
// ==========================================
// Time Complexity  : O(k * n^2)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. Sort houses in ascending order.
2. Precompute cost[i][j]: minimum distance cost to serve houses[i..j] with 1 mailbox (placed at median).
     cost[i][j] = cost[i+1][j-1] + houses[j] - houses[i]
3. Initialize dp matrix of size (k + 1) x n with INT_MAX.
4. dp[1][i] = cost[0][i].
5. For m from 2 to k:
     For i from m-1 to n-1:
         For j from 0 to i-1:
             dp[m][i] = min(dp[m][i], dp[m - 1][j] + cost[j + 1][i])
6. Return dp[k][n - 1].
*/

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();
        sort(houses.begin(), houses.end());

        // Precompute cost[i][j]: distance when 1 mailbox is placed at median of houses[i..j]
        vector<vector<int>> cost(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int median = houses[(i + j) / 2];
                for (int m = i; m <= j; m++) {
                    cost[i][j] += abs(houses[m] - median);
                }
            }
        }

        const int INF = 1e8;
        vector<vector<int>> dp(k + 1, vector<int>(n, INF));

        // Base case: 1 mailbox for houses[0..i]
        for (int i = 0; i < n; i++) {
            dp[1][i] = cost[0][i];
        }

        // DP for 2 to k mailboxes
        for (int m = 2; m <= k; m++) {
            for (int i = m - 1; i < n; i++) {
                for (int j = 0; j < i; j++) {
                    dp[m][i] = min(dp[m][i], dp[m - 1][j] + cost[j + 1][i]);
                }
            }
        }

        return dp[k][n - 1];
    }
};
