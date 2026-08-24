// Link: https://leetcode.com/problems/partition-equal-subset-sum/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (0/1 Knapsack 1D Boolean DP)
// ==========================================
// Time Complexity  : O(n * (sum / 2))
// Space Complexity : O(sum / 2)
/*
PSEUDOCODE:
1. Total sum = sum(nums).
2. If sum % 2 != 0 return false.
3. target = sum / 2.
4. dp array of size target + 1 with false, dp[0] = true.
5. For each num in nums:
     For j from target down to num:
         dp[j] = dp[j] || dp[j - num]
6. Return dp[target].
*/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) totalSum += num;

        if (totalSum % 2 != 0) return false;

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int num : nums) {
            // Traverse backwards to use each number at most once
            for (int j = target; j >= num; j--) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
