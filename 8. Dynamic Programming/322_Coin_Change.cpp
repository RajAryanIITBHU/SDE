// Link: https://leetcode.com/problems/coin-change/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D DP Array - Unbounded Knapsack)
// ==========================================
// Time Complexity  : O(amount * coins.size())
// Space Complexity : O(amount)
/*
PSEUDOCODE:
1. Initialize dp array of size amount + 1 with amount + 1, dp[0] = 0.
2. For i from 1 to amount:
     For each c in coins:
         if i - c >= 0:
             dp[i] = min(dp[i], dp[i - c] + 1)
3. Return dp[amount] > amount ? -1 : dp[amount].
*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; i++) {
            for (int c : coins) {
                if (i - c >= 0) {
                    dp[i] = min(dp[i], dp[i - c] + 1);
                }
            }
        }

        return (dp[amount] > amount) ? -1 : dp[amount];
    }
};
