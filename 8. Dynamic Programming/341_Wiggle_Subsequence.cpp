// Link: https://leetcode.com/problems/wiggle-subsequence/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy / Space-Optimized DP)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If n < 2 return n.
2. up = 1, down = 1.
3. For i from 1 to n-1:
     if nums[i] > nums[i - 1]:
         up = down + 1
     else if nums[i] < nums[i - 1]:
         down = up + 1
4. Return max(up, down).
*/

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;

        int up = 1;   // Max length ending with an upward slope
        int down = 1; // Max length ending with a downward slope

        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up = down + 1;
            } else if (nums[i] < nums[i - 1]) {
                down = up + 1;
            }
        }

        return max(up, down);
    }
};
