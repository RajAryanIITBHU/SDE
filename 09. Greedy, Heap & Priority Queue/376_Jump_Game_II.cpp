// Link: https://leetcode.com/problems/jump-game-ii/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Range Expansion)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. jumps = 0, currentEnd = 0, farthest = 0.
2. For i from 0 to n-2:
     farthest = max(farthest, i + nums[i])
     if i == currentEnd:
         jumps++
         currentEnd = farthest
3. Return jumps.
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0;
        int currentEnd = 0;
        int farthest = 0;

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);

            if (i == currentEnd) {
                jumps++;
                currentEnd = farthest;
            }
        }

        return jumps;
    }
};
