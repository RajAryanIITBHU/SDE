// Link: https://leetcode.com/problems/house-robber-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Circular House Robber: Dual Linear Subarray Robbery)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If n == 1 return nums[0].
2. Helper robLinear(start, end):
     prev2 = 0, prev1 = 0
     For i from start to end:
         curr = max(prev1, prev2 + nums[i])
         prev2 = prev1
         prev1 = curr
     return prev1
3. Return max(robLinear(0, n - 2), robLinear(1, n - 1)).
*/

class Solution {
private:
    int robLinear(vector<int>& nums, int start, int end) {
        int prev2 = 0;
        int prev1 = 0;

        for (int i = start; i <= end; i++) {
            int curr = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        // Case 1: Exclude last house (rob 0..n-2)
        // Case 2: Exclude first house (rob 1..n-1)
        return max(robLinear(nums, 0, n - 2), robLinear(nums, 1, n - 1));
    }
};
