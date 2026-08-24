/*
 * ============================================================================
 * Concept: Find Peak Element
 * Subtopic: Binary Search & Search on Answer
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Finds a local peak element `nums[i]` where `nums[i] > nums[i-1]` and `nums[i] > nums[i+1]`.
Works in O(log N) using binary search by following the ascending slope: if `nums[mid] < nums[mid+1]`, a peak MUST exist in the right half.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log N) time complexity.
 * - Space Complexity: O(1) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Find Peak Element (LC 162).
- Peak Index in a Mountain Array (LC 852).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. 1D Peak Element (LC 162).
2. 2D Peak Element (LC 1901 - Binary search on columns + max element in row).
 */

#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(const vector<int>& nums) {
    int low = 0, high = nums.size() - 1;
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < nums[mid + 1]) low = mid + 1;
        else high = mid;
    }
    return low;
}

int main() {
    vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
    cout << "Peak Index: " << findPeakElement(nums) << "\n";
    return 0;
}
