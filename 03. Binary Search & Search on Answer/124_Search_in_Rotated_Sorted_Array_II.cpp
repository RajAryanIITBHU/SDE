// Link: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search with Duplicate Handling)
// ==========================================
// Time Complexity  : O(log n) average, O(n) worst case with duplicates
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. low = 0, high = n - 1.
2. While low <= high:
     mid = low + (high - low) / 2
     if nums[mid] == target -> return true
     
     // Ambiguous case due to duplicates
     if nums[low] == nums[mid] && nums[mid] == nums[high]:
         low++, high--
         continue
     
     // Left half sorted
     if nums[low] <= nums[mid]:
         if nums[low] <= target && target < nums[mid]:
             high = mid - 1
         else:
             low = mid + 1
     // Right half sorted
     else:
         if nums[mid] < target && target <= nums[high]:
             low = mid + 1
         else:
             high = mid - 1
3. Return false.
*/

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return true;
            }

            // If duplicates obscure which half is sorted, shrink both ends
            if (nums[low] == nums[mid] && nums[mid] == nums[high]) {
                low++;
                high--;
                continue;
            }

            // Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            } 
            // Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
        }

        return false;
    }
};
