/*
 * ============================================================================
 * Concept: Search in Rotated Sorted Array
 * Subtopic: Binary Search & Search on Answer
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Searches in an array sorted then rotated at an unknown pivot.
Key insight: At least one half (`[low ... mid]` or `[mid ... high]`) must be strictly sorted.
Determine which half is sorted, then check if target lies within that sorted range.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log N) average/worst for unique elements, O(N) worst for duplicates.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Search in Rotated Sorted Array (LC 33 & LC 81).
- Find Minimum in Rotated Sorted Array (LC 153 & LC 154).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Unique elements (LC 33).
2. Duplicate elements (LC 81: handle `nums[low] == nums[mid] == nums[high]` by `low++`, `high--`).
 */

#include <iostream>
#include <vector>

using namespace std;

int searchRotated(const vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;

        // Check if left half is sorted
        if (nums[low] <= nums[mid]) {
            if (nums[low] <= target && target < nums[mid]) high = mid - 1;
            else low = mid + 1;
        } else { // Right half is sorted
            if (nums[mid] < target && target <= nums[high]) low = mid + 1;
            else high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Index of 0: " << searchRotated(nums, 0) << "\n";
    return 0;
}
