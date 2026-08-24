// Link: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Partitions)
// ==========================================
// Time Complexity  : O(log(min(n, m)))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Ensure nums1 is the smaller array (if not, swap).
2. Total elements: total = n + m, half = (total + 1) / 2.
3. Binary search on partition cut in nums1: low = 0, high = n.
4. While low <= high:
     cut1 = low + (high - low) / 2
     cut2 = half - cut1
     
     l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1]
     l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1]
     r1 = (cut1 == n) ? INT_MAX : nums1[cut1]
     r2 = (cut2 == m) ? INT_MAX : nums2[cut2]
     
     if l1 <= r2 && l2 <= r1:
         if total % 2 != 0 -> return max(l1, l2)
         else -> return (max(l1, l2) + min(r1, r2)) / 2.0
     else if l1 > r2:
         high = cut1 - 1
     else:
         low = cut1 + 1
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Ensure binary search is performed on the smaller array
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int n = nums1.size();
        int m = nums2.size();

        int low = 0;
        int high = n;
        int half = (n + m + 1) / 2;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = half - cut1;

            int l1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int l2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int r1 = (cut1 == n) ? INT_MAX : nums1[cut1];
            int r2 = (cut2 == m) ? INT_MAX : nums2[cut2];

            // Valid partition found
            if (l1 <= r2 && l2 <= r1) {
                if ((n + m) % 2 != 0) {
                    return max(l1, l2);
                } else {
                    return (max(l1, l2) + min(r1, r2)) / 2.0;
                }
            } else if (l1 > r2) {
                high = cut1 - 1; // Move cut1 to the left
            } else {
                low = cut1 + 1; // Move cut1 to the right
            }
        }

        return 0.0;
    }
};
