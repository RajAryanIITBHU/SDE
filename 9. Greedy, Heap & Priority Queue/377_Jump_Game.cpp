// Link: https://leetcode.com/problems/jump-game/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Greedy Max Reachable Index)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. maxReach = 0.
2. For i from 0 to n-1:
     if i > maxReach return false
     maxReach = max(maxReach, i + nums[i])
3. Return true.
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (i > maxReach) {
                return false;
            }
            maxReach = max(maxReach, i + nums[i]);
        }

        return true;
    }
};
