// Link: https://leetcode.com/problems/uncrossed-lines/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (LCS Dynamic Programming on Arrays)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(m)
/*
PSEUDOCODE:
Uncrossed lines between nums1 and nums2 is equivalent to Longest Common Subsequence.
1. Initialize dp vector of size m + 1 with 0.
2. For i from 1 to n:
     prev = 0
     For j from 1 to m:
         temp = dp[j]
         if nums1[i-1] == nums2[j-1]:
             dp[j] = 1 + prev
         else:
             dp[j] = max(dp[j], dp[j-1])
         prev = temp
3. Return dp[m].
*/

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> dp(m + 1, 0);

        for (int i = 1; i <= n; i++) {
            int prev = 0;

            for (int j = 1; j <= m; j++) {
                int temp = dp[j];

                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[j] = 1 + prev;
                } else {
                    dp[j] = max(dp[j], dp[j - 1]);
                }

                prev = temp;
            }
        }

        return dp[m];
    }
};
