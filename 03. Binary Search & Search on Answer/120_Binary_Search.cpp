// Link: https://leetcode.com/problems/binary-search/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Standard Iterative Binary Search)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. low = 0, high = n - 1.
2. While low <= high:
     mid = low + (high - low) / 2
     if nums[mid] == target -> return mid
     else if nums[mid] < target -> low = mid + 1
     else -> high = mid - 1
3. Return -1.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = (int)nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return -1;
    }
};
