// Link: https://leetcode.com/problems/remove-element/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers - Overwrite Non-Target)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
1. Initialize i = 0.
2. For j from 0 to n-1:
     if nums[j] != val:
         nums[i] = nums[j]
         i++
3. Return i.
*/

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0; // Pointer for placing non-val elements

        for (int j = 0; j < n; j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }

        return i;
    }
};
