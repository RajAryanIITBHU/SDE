// Link: https://leetcode.com/problems/move-zeroes/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers / In-place Swap)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize pointer i = 0 (points to the first zero).
2. For pointer j from 0 to n-1:
     if nums[j] != 0:
         swap(nums[i], nums[j])
         i++
*/

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0; // Tracks position for next non-zero element

        for (int j = 0; j < n; j++) {
            if (nums[j] != 0) {
                swap(nums[i], nums[j]);
                i++;
            }
        }
    }
};
