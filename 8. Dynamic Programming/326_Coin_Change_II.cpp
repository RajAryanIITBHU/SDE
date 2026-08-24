// Link: https://leetcode.com/problems/coin-change-ii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D DP Array - Unbounded Knapsack Combinations)
// ==========================================
// Time Complexity  : O(coins.size() * amount)
// Space Complexity : O(amount)
/*
PSEUDOCODE:
1. Initialize dp array of size amount + 1 with 0, dp[0] = 1.
2. For each c in coins:
     For j from c to amount:
         dp[j] += dp[j - c]
3. Return dp[amount].
*/

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;

        for (int c : coins) {
            for (int j = c; j <= amount; j++) {
                dp[j] += dp[j - c];
            }
        }

        return dp[amount];
    }
};
