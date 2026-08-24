// Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search with High Comparison)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize low = 0, high = n - 1.
2. While low < high:
     mid = low + (high - low) / 2
     // If mid element > high element, the inflection point / minimum is strictly in right half
     if nums[mid] > nums[high]:
         low = mid + 1
     // Otherwise minimum is at mid or in left half
     else:
         high = mid
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
                low = mid + 1; // Minimum lies to the right of mid
            } else {
                high = mid; // Minimum is at mid or to the left of mid
            }
        }

        return nums[low];
    }
};
