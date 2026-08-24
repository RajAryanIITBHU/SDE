// Link: https://leetcode.com/problems/combination-sum-iv/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D DP Array - Permutations)
// ==========================================
// Time Complexity  : O(target * nums.size())
// Space Complexity : O(target)
/*
PSEUDOCODE:
1. Initialize dp vector of size target + 1 with 0, dp[0] = 1.
2. For i from 1 to target:
     For each num in nums:
         if i - num >= 0:
             dp[i] += dp[i - num]
3. Return dp[target].
*/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }

        return dp[target];
    }
};
