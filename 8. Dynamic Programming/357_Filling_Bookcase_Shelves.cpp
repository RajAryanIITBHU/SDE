// Link: https://leetcode.com/problems/filling-bookcase-shelves/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D DP Array)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize dp vector of size n + 1 with INT_MAX, dp[0] = 0.
2. For i from 1 to n:
     widthSum = 0, maxHeight = 0
     For j from i down to 1:
         widthSum += books[j-1][0]
         if widthSum > shelfWidth break
         maxHeight = max(maxHeight, books[j-1][1])
         dp[i] = min(dp[i], dp[j - 1] + maxHeight)
3. Return dp[n].
*/

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int n = books.size();
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            int widthSum = 0;
            int maxHeight = 0;

            // Place books from j-1 to i-1 on the new current shelf
            for (int j = i; j >= 1; j--) {
                widthSum += books[j - 1][0];
                if (widthSum > shelfWidth) break;

                maxHeight = max(maxHeight, books[j - 1][1]);
                dp[i] = min(dp[i], dp[j - 1] + maxHeight);
            }
        }

        return dp[n];
    }
};
