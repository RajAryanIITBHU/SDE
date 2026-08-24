// Link: https://leetcode.com/problems/search-in-rotated-sorted-array/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Linear Scan)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. For i from 0 to n-1:
     if nums[i] == target -> return i
2. Return -1.
*/

class SolutionBruteForce {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == target) return i;
        }
        return -1;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Binary Search on Rotated Array)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize low = 0, high = n - 1.
2. While low <= high:
     mid = low + (high - low) / 2
     if nums[mid] == target -> return mid
     
     // Check if left half is sorted
     if nums[low] <= nums[mid]:
         if nums[low] <= target && target < nums[mid]:
             high = mid - 1
         else:
             low = mid + 1
     // Otherwise right half is sorted
     else:
         if nums[mid] < target && target <= nums[high]:
             low = mid + 1
         else:
             high = mid - 1
3. Return -1.
*/

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }

            // Case 1: Left half is sorted
            if (nums[low] <= nums[mid]) {
                if (nums[low] <= target && target < nums[mid]) {
                    high = mid - 1; // Target is in the left sorted portion
                } else {
                    low = mid + 1;
                }
            } 
            // Case 2: Right half is sorted
            else {
                if (nums[mid] < target && target <= nums[high]) {
                    low = mid + 1; // Target is in the right sorted portion
                } else {
                    high = mid - 1;
                }
            }
        }

        return -1;
    }
};
