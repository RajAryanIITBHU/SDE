/*
 * ============================================================================
 * Concept: Standard Binary Search
 * Subtopic: Binary Search & Search on Answer
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Divides a search space in half at each step by comparing target with `mid = low + (high - low) / 2`.
Requires a sorted or monotonic sequence.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log N) time complexity.
 * - Space Complexity: O(1) iterative, O(log N) recursive stack.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Searching for an element in a sorted array.
- Monotonic sequence lookup.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Standard Binary Search (LC 704).
2. Overflow prevention: `mid = low + (high - low) / 2` instead of `(low + high) / 2`.
 */

#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<int>& nums, int target) {
    int low = 0, high = (int)nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }
    return -1;
}

int main() {
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << "Found index of 9: " << binarySearch(nums, 9) << "\n";
    return 0;
}
