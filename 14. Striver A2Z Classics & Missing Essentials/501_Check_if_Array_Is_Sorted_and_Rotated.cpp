// Link: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Count Drop Points)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
In a sorted and rotated array, nums[i] > nums[(i + 1) % n] can happen at most ONCE.
1. count = 0, n = nums.size().
2. For i from 0 to n-1:
     if nums[i] > nums[(i + 1) % n]:
         count++
3. Return count <= 1.
*/

class Solution {
public:
    bool check(vector<int>& nums) {
        int count = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] > nums[(i + 1) % n]) {
                count++;
            }
        }

        return count <= 1;
    }
};
