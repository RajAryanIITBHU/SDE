// Link: https://leetcode.com/problems/triangle/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bottom-Up 1D DP)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize dp vector with the bottom row of the triangle.
2. For i from n-2 down to 0:
     For j from 0 to i:
         dp[j] = triangle[i][j] + min(dp[j], dp[j + 1])
3. Return dp[0].
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }

        return dp[0];
    }
};
