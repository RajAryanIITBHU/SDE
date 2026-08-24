/*
 * ============================================================================
 * Concept: Sliding Window (Non-Shrinkable Window Tracking)
 * Subtopic: Two Pointers, Sliding Window & Strings
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Instead of shrinking the window when invalid, a non-shrinkable window only grows when a larger valid window is found.
`right - left` maintains the maximum valid window size seen so far. If condition is invalid, shift `left++` along with `right++`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - single pass with no nested while loops.
 * - Space Complexity: O(1) or O(K) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Finding ONLY the maximum length of a valid subarray/substring.
- Simplifies code by replacing shrinking `while` loop with a single `if`.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Max Consecutive Ones III (LC 1004).
2. Longest Repeating Character Replacement (LC 424).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Max Consecutive Ones III (LC 1004 - Non-shrinkable window)
int longestOnes(const vector<int>& nums, int k) {
    int left = 0, right = 0;
    int zero_count = 0;

    for (right = 0; right < (int)nums.size(); ++right) {
        if (nums[right] == 0) zero_count++;
        if (zero_count > k) {
            if (nums[left] == 0) zero_count--;
            left++; // Shift window right without shrinking size
        }
    }
    return right - left;
}

int main() {
    vector<int> nums = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    cout << "Max Consecutive Ones (k=2): " << longestOnes(nums, 2) << "\n";
    return 0;
}
