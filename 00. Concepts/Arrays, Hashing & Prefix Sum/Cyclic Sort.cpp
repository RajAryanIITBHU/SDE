/*
 * ============================================================================
 * Concept: Cyclic Sort Pattern
 * Subtopic: Arrays, Hashing & Prefix Sum
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Cyclic Sort places numbers in range `[1, N]` or `[0, N-1]` into their correct 0-indexed positions `nums[i] == i + 1`.
If `nums[i]` is not at index `nums[i] - 1`, swap `nums[i]` with the element at `nums[i] - 1`. Repeat until element is placed correctly.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - each element is swapped at most once.
 * - Space Complexity: O(1) - in-place sorting without auxiliary memory.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Input array contains numbers in range `1 to N` or `0 to N`.
- Problem asks to find missing number, duplicates, or first missing positive in O(N) time and O(1) space.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Missing Number (LC 268).
2. Find All Numbers Disappeared in an Array (LC 448).
3. Find the Duplicate Number (LC 287).
4. First Missing Positive (LC 41).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// First Missing Positive (LC 41)
int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (nums[i] != i + 1) return i + 1;
    }
    return n + 1;
}

int main() {
    vector<int> nums = {3, 4, -1, 1};
    cout << "First Missing Positive: " << firstMissingPositive(nums) << "\n";
    return 0;
}
