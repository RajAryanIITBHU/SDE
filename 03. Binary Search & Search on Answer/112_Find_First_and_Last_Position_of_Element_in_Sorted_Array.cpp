// Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Dual Binary Search)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper findFirst(target):
     low = 0, high = n - 1, first = -1
     While low <= high:
         mid = low + (high - low) / 2
         if nums[mid] == target -> first = mid, high = mid - 1 (search left)
         else if nums[mid] < target -> low = mid + 1
         else -> high = mid - 1
     return first
2. Helper findLast(target):
     low = 0, high = n - 1, last = -1
     While low <= high:
         mid = low + (high - low) / 2
         if nums[mid] == target -> last = mid, low = mid + 1 (search right)
         else if nums[mid] < target -> low = mid + 1
         else -> high = mid - 1
     return last
3. Return {findFirst(target), findLast(target)}.
*/

class Solution {
private:
    int findFirst(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;
        int first = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                first = mid;
                high = mid - 1; // Look for earlier occurrence on the left
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return first;
    }

    int findLast(vector<int>& nums, int target) {
        int low = 0, high = (int)nums.size() - 1;
        int last = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                last = mid;
                low = mid + 1; // Look for later occurrence on the right
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return last;
    }

public:
    vector<int> searchRange(vector<int>& nums, int target) {
        return {findFirst(nums, target), findLast(nums, target)};
    }
};
