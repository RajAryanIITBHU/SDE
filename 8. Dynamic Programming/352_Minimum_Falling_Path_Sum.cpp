// Link: https://leetcode.com/problems/minimum-falling-path-sum/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Rolling Row DP)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize dp vector with first row matrix[0].
2. For i from 1 to n-1:
     vector<int> nextRow(n)
     For j from 0 to n-1:
         left = (j > 0) ? dp[j - 1] : INT_MAX
         mid = dp[j]
         right = (j < n - 1) ? dp[j + 1] : INT_MAX
         nextRow[j] = matrix[i][j] + min({left, mid, right})
     dp = nextRow
3. Return min_element(dp.begin(), dp.end()).
*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp = matrix[0];

        for (int i = 1; i < n; i++) {
            vector<int> nextRow(n);

            for (int j = 0; j < n; j++) {
                int left = (j > 0) ? dp[j - 1] : INT_MAX;
                int mid = dp[j];
                int right = (j < n - 1) ? dp[j + 1] : INT_MAX;

                nextRow[j] = matrix[i][j] + min({left, mid, right});
            }

            dp = nextRow;
        }

        return *min_element(dp.begin(), dp.end());
    }
};
