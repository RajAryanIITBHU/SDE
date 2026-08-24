/*
 * ============================================================================
 * Concept: Two Pointers (Same Direction / Fast & Slow)
 * Subtopic: Two Pointers, Sliding Window & Strings
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Maintains two pointers `slow` and `fast` moving from left to right at different rates or under different conditions.
Commonly used for array compaction, in-place deduplication, and partitioning.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - single pass.
 * - Space Complexity: O(1) - in-place array modification.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - In-place element removal or deduplication in sorted array.
- Moving specific values (e.g. zeroes) to the end of the array.
- Partitioning elements without extra memory.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Move Zeroes (LC 283).
2. Remove Duplicates from Sorted Array (LC 26).
3. Remove Element (LC 27).
 */

#include <iostream>
#include <vector>

using namespace std;

// Move Zeroes (LC 283)
void moveZeroes(vector<int>& nums) {
    int slow = 0;
    for (int fast = 0; fast < (int)nums.size(); ++fast) {
        if (nums[fast] != 0) {
            swap(nums[slow], nums[fast]);
            slow++;
        }
    }
}

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    moveZeroes(nums);
    cout << "Moved Zeroes: ";
    for (int x : nums) cout << x << " ";
    cout << "\n";
    return 0;
}
