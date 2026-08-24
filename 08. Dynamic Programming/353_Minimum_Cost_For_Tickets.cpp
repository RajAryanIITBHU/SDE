// Link: https://leetcode.com/problems/minimum-cost-for-tickets/

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Calendar DP)
// ==========================================
// Time Complexity  : O(maxDay) = O(365) = O(1)
// Space Complexity : O(maxDay) = O(365) = O(1)
/*
PSEUDOCODE:
1. Store travel days in unordered_set travelDays.
2. lastDay = days.back().
3. Initialize dp array of size lastDay + 1 with 0.
4. For i from 1 to lastDay:
     if not travelDays.count(i):
         dp[i] = dp[i - 1]
     else:
         cost1 = dp[max(0, i - 1)] + costs[0]
         cost7 = dp[max(0, i - 7)] + costs[1]
         cost30 = dp[max(0, i - 30)] + costs[2]
         dp[i] = min({cost1, cost7, cost30})
5. Return dp[lastDay].
*/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel(days.begin(), days.end());
        int lastDay = days.back();

        vector<int> dp(lastDay + 1, 0);

        for (int i = 1; i <= lastDay; i++) {
            if (travel.find(i) == travel.end()) {
                dp[i] = dp[i - 1]; // No travel on day i
            } else {
                int cost1 = dp[max(0, i - 1)] + costs[0];
                int cost7 = dp[max(0, i - 7)] + costs[1];
                int cost30 = dp[max(0, i - 30)] + costs[2];

                dp[i] = min({cost1, cost7, cost30});
            }
        }

        return dp[lastDay];
    }
};
