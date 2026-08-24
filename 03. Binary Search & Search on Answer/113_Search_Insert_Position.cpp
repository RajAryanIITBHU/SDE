// Link: https://leetcode.com/problems/search-insert-position/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Lower Bound Binary Search)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize low = 0, high = n - 1, ans = n.
2. While low <= high:
     mid = low + (high - low) / 2
     if nums[mid] >= target:
         ans = mid // Potential insertion position
         high = mid - 1
     else:
         low = mid + 1
3. Return ans.
*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;
        int ans = n; // Default to inserting at the end

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Find first element >= target
            if (nums[mid] >= target) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
