// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search with Duplicate Shrinking)
// ==========================================
// Time Complexity  : O(log n) average, O(n) worst case
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. low = 0, high = n - 1.
2. While low < high:
     mid = low + (high - low) / 2
     if nums[mid] > nums[high]:
         low = mid + 1 // Minimum strictly in right half
     else if nums[mid] < nums[high]:
         high = mid // Minimum in left half or at mid
     else:
         high-- // Indistinguishable due to duplicates, shrink boundary
3. Return nums[low].
*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = (int)nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] > nums[high]) {
                low = mid + 1;
            } else if (nums[mid] < nums[high]) {
                high = mid;
            } else {
                // When nums[mid] == nums[high], high can be decremented safely
                high--;
            }
        }

        return nums[low];
    }
};
