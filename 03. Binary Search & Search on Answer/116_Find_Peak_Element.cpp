// Link: https://leetcode.com/problems/find-peak-element/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Slope)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize low = 0, high = n - 1.
2. While low < high:
     mid = low + (high - low) / 2
     // If ascending slope, a peak must exist to the right
     if nums[mid] < nums[mid + 1]:
         low = mid + 1
     // If descending slope, a peak is at mid or to the left
     else:
         high = mid
3. Return low.
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0;
        int high = (int)nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] < nums[mid + 1]) {
                low = mid + 1; // Climbing uphill, peak lies to the right
            } else {
                high = mid; // Going downhill, peak is at mid or to the left
            }
        }

        return low;
    }
};
