// Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Space-Optimized DP with Modulo)
// ==========================================
// Time Complexity  : O(n * target * k)
// Space Complexity : O(target)
/*
PSEUDOCODE:
1. const int MOD = 1e9 + 7.
2. Initialize dp vector of size target + 1 with 0, dp[0] = 1.
3. For dice from 1 to n:
     vector<int> nextDP(target + 1, 0)
     For s from 1 to target:
         For face from 1 to k:
             if s - face >= 0:
                 nextDP[s] = (nextDP[s] + dp[s - face]) % MOD
     dp = nextDP
4. Return dp[target].
*/

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1e9 + 7;
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int dice = 1; dice <= n; dice++) {
            vector<int> nextDP(target + 1, 0);

            for (int s = 1; s <= target; s++) {
                for (int face = 1; face <= k && s - face >= 0; face++) {
                    nextDP[s] = (nextDP[s] + dp[s - face]) % MOD;
                }
            }

            dp = nextDP;
        }

        return dp[target];
    }
};
