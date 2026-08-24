// Link: https://leetcode.com/problems/minimum-cost-to-merge-stones/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Interval DP on K Piles)
// ==========================================
// Time Complexity  : O(n^3 / k)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. If (n - 1) % (k - 1) != 0 return -1.
2. Build prefix sum array prefix.
3. Initialize dp matrix of size n x n with 0.
4. For len from k to n:
     For i from 0 to n - len:
         j = i + len - 1
         dp[i][j] = INT_MAX
         For mid from i to j-1 with step (k - 1):
             dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j])
         if (len - 1) % (k - 1) == 0:
             dp[i][j] += prefix[j + 1] - prefix[i] // Merge the k piles into 1 pile
5. Return dp[0][n - 1].
*/

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0) return -1;

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int len = k; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;
                dp[i][j] = INT_MAX;

                for (int mid = i; mid < j; mid += (k - 1)) {
                    dp[i][j] = min(dp[i][j], dp[i][mid] + dp[mid + 1][j]);
                }

                if ((len - 1) % (k - 1) == 0) {
                    dp[i][j] += prefix[j + 1] - prefix[i];
                }
            }
        }

        return dp[0][n - 1];
    }
};
