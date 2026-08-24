// Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Interval DP on Sorted Cuts)
// ==========================================
// Time Complexity  : O(m^3), where m = cuts.size()
// Space Complexity : O(m^2)
/*
PSEUDOCODE:
1. Append 0 and n to cuts and sort: cuts = [0, ...cuts, n].
2. m = cuts.size().
3. Initialize dp matrix of size m x m with 0.
4. For len from 2 to m-1:
     For left from 0 to m - len - 1:
         right = left + len
         dp[left][right] = INT_MAX
         For k from left + 1 to right - 1:
             cost = cuts[right] - cuts[left] + dp[left][k] + dp[k][right]
             dp[left][right] = min(dp[left][right], cost)
5. Return dp[0][m - 1].
*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int m = cuts.size();
        vector<vector<int>> dp(m, vector<int>(m, 0));

        for (int len = 2; len < m; len++) {
            for (int left = 0; left < m - len; left++) {
                int right = left + len;
                dp[left][right] = INT_MAX;

                for (int k = left + 1; k < right; k++) {
                    int cost = cuts[right] - cuts[left] + dp[left][k] + dp[k][right];
                    dp[left][right] = min(dp[left][right], cost);
                }
            }
        }

        return dp[0][m - 1];
    }
};
