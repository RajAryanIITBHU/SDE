// Link: https://leetcode.com/problems/single-element-in-a-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Even/Odd Index Parity)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
In array with duplicate pairs before the single element:
  - 1st instance is at EVEN index, 2nd instance is at ODD index.
After the single element:
  - 1st instance is at ODD index, 2nd instance is at EVEN index.

1. low = 0, high = n - 2.
2. While low <= high:
     mid = low + (high - low) / 2
     // Partner index: if mid is even -> mid + 1; if mid is odd -> mid - 1
     // Bit trick: mid ^ 1 gives the partner index!
     if nums[mid] == nums[mid ^ 1]:
         low = mid + 1 // Pattern intact, single element is on the right
     else:
         high = mid - 1 // Pattern disrupted, single element is on the left or at mid
3. Return nums[low].
*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = (int)nums.size() - 2;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Partner index check using XOR (even^1 = even+1, odd^1 = odd-1)
            if (nums[mid] == nums[mid ^ 1]) {
                low = mid + 1; // Left half is normal, single element is on right
            } else {
                high = mid - 1; // Disruption occurred, single element is on left
            }
        }

        return nums[low];
    }
};
