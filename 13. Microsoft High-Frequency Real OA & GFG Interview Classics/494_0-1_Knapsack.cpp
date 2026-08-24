// Link: https://www.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Dynamic Programming)
// ==========================================
// Time Complexity  : O(n * W)
// Space Complexity : O(W)
/*
PSEUDOCODE:
1. dp array of size W + 1 initialized to 0.
2. For i from 0 to n-1:
     For w from W down to wt[i]:
         dp[w] = max(dp[w], val[i] + dp[w - wt[i]])
3. Return dp[W].
*/

class Solution {
public:
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = wt.size();
        vector<int> dp(W + 1, 0);

        for (int i = 0; i < n; i++) {
            for (int w = W; w >= wt[i]; w--) {
                dp[w] = max(dp[w], val[i] + dp[w - wt[i]]);
            }
        }

        return dp[W];
    }
};
