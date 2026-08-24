// Link: https://leetcode.com/problems/target-sum/

#include <iostream>
#include <vector>
#include <cmath>
#include <numeric>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (0/1 Knapsack Subset Sum Reduction)
// ==========================================
// Time Complexity  : O(n * targetSubsetSum)
// Space Complexity : O(targetSubsetSum)
/*
PSEUDOCODE:
Let P be subset of '+' and N be subset of '-':
  sum(P) - sum(N) = target
  sum(P) + sum(N) = totalSum
  2 * sum(P) = target + totalSum  =>  sum(P) = (target + totalSum) / 2
1. If abs(target) > totalSum || (target + totalSum) % 2 != 0 return 0.
2. targetSubset = (target + totalSum) / 2.
3. Initialize dp array of size targetSubset + 1 with 0, dp[0] = 1.
4. For each num in nums:
     For j from targetSubset down to num:
         dp[j] += dp[j - num]
5. Return dp[targetSubset].
*/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (abs(target) > totalSum || (target + totalSum) % 2 != 0) {
            return 0;
        }

        int targetSubset = (target + totalSum) / 2;
        vector<int> dp(targetSubset + 1, 0);
        dp[0] = 1;

        for (int num : nums) {
            for (int j = targetSubset; j >= num; j--) {
                dp[j] += dp[j - num];
            }
        }

        return dp[targetSubset];
    }
};
