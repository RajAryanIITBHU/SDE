// Link: https://leetcode.com/problems/two-city-scheduling/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Sort by Cost Difference)
// ==========================================
// Time Complexity  : O(n log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Sort people by cost difference: (costA - costB) in ascending order.
     Smaller (costA - costB) means biggest savings sending to City A.
2. totalCost = 0.
3. For i from 0 to n-1:
     if i < n / 2: totalCost += costs[i][0] (Send to City A)
     else: totalCost += costs[i][1] (Send to City B)
4. Return totalCost.
*/

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        // Sort by relative gain of flying to A over B
        sort(costs.begin(), costs.end(), [](const vector<int>& a, const vector<int>& b) {
            return (a[0] - a[1]) < (b[0] - b[1]);
        });

        int totalCost = 0;
        int n = costs.size() / 2;

        for (int i = 0; i < 2 * n; i++) {
            if (i < n) {
                totalCost += costs[i][0]; // Send first n to City A
            } else {
                totalCost += costs[i][1]; // Send remaining n to City B
            }
        }

        return totalCost;
    }
};
