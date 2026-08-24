// Link: https://leetcode.com/problems/house-robber/

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
1. prev2 = 0, prev1 = 0.
2. For each num in nums:
     curr = max(prev1, prev2 + num)
     prev2 = prev1
     prev1 = curr
3. Return prev1.
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int prev2 = 0; // Max money robbed up to i-2
        int prev1 = 0; // Max money robbed up to i-1

        for (int num : nums) {
            int curr = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
