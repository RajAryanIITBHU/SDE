// Link: https://leetcode.com/problems/last-stone-weight-ii/

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (0/1 Knapsack Subset Sum Closest to Half)
// ==========================================
// Time Complexity  : O(n * (totalSum / 2))
// Space Complexity : O(totalSum / 2)
/*
PSEUDOCODE:
Smashing stones reduces to partitioning stones into two subsets S1 and S2 to minimize |S1 - S2|.
1. totalSum = sum(stones).
2. target = totalSum / 2.
3. Initialize dp array of size target + 1 with false, dp[0] = true.
4. For each stone in stones:
     For j from target down to stone:
         dp[j] = dp[j] || dp[j - stone]
5. Find max achievable sum s1 <= target where dp[s1] is true.
6. Return totalSum - 2 * s1.
*/

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int totalSum = 0;
        for (int s : stones) totalSum += s;

        int target = totalSum / 2;
        vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (int s : stones) {
            for (int j = target; j >= s; j--) {
                dp[j] = dp[j] || dp[j - s];
            }
        }

        int maxS1 = 0;
        for (int j = target; j >= 0; j--) {
            if (dp[j]) {
                maxS1 = j;
                break;
            }
        }

        return totalSum - 2 * maxS1;
    }
};
