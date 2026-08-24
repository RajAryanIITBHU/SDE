// Link: https://leetcode.com/problems/delete-and-earn/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (House Robber Reduction on Value Sums)
// ==========================================
// Time Complexity  : O(N + maxVal)
// Space Complexity : O(maxVal)
/*
PSEUDOCODE:
1. Find max value maxVal in nums.
2. Build totalPoints array: totalPoints[v] = v * count(v).
3. Run House Robber DP on totalPoints:
     prev2 = 0, prev1 = 0
     For i from 0 to maxVal:
         curr = max(prev1, prev2 + totalPoints[i])
         prev2 = prev1
         prev1 = curr
4. Return prev1.
*/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if (nums.empty()) return 0;

        int maxVal = 0;
        for (int num : nums) {
            maxVal = max(maxVal, num);
        }

        vector<int> totalPoints(maxVal + 1, 0);
        for (int num : nums) {
            totalPoints[num] += num;
        }

        // House Robber DP
        int prev2 = 0;
        int prev1 = 0;

        for (int i = 0; i <= maxVal; i++) {
            int curr = max(prev1, prev2 + totalPoints[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
