// Link: https://leetcode.com/problems/min-cost-climbing-stairs/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Space-Optimized DP)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. prev2 = cost[0], prev1 = cost[1].
2. For i from 2 to n-1:
     curr = cost[i] + min(prev1, prev2)
     prev2 = prev1
     prev1 = curr
3. Return min(prev1, prev2).
*/

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        int prev2 = cost[0];
        int prev1 = cost[1];

        for (int i = 2; i < n; i++) {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }

        return min(prev1, prev2);
    }
};
