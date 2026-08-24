// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers - Fast & Slow)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
1. If nums is empty return 0.
2. Initialize slow pointer i = 0.
3. For fast pointer j from 1 to n-1:
     if nums[j] != nums[i]:
         i++
         nums[i] = nums[j]
4. Return i + 1 (length of unique elements).
*/

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;

        int i = 0; // Index of last unique element placed

        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }

        return i + 1;
    }
};
