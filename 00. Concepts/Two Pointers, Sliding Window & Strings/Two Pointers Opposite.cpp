/*
 * ============================================================================
 * Concept: Two Pointers (Opposite Direction)
 * Subtopic: Two Pointers, Sliding Window & Strings
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Maintains two pointers initialized at opposite ends (`left = 0`, `right = N - 1`) moving towards each other based on conditions.
Extremely useful for sorted array pair searches, palindrome validation, and bounding area optimization.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - single pass traversing towards center.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Sorted array input searching for target sum.
- Palindrome verification (matching left and right characters).
- Container With Most Water (greedy pointer contraction based on height).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Two Sum II - Input Array Is Sorted (LC 167).
2. Valid Palindrome (LC 125 & LC 680).
3. Container With Most Water (LC 11).
4. 3Sum / 4Sum (Sort array + fix outer loop + opposite two pointers).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Container With Most Water (LC 11)
int maxArea(const vector<int>& height) {
    int left = 0, right = height.size() - 1;
    int max_water = 0;
    while (left < right) {
        int h = min(height[left], height[right]);
        max_water = max(max_water, h * (right - left));
        if (height[left] < height[right]) left++;
        else right--;
    }
    return max_water;
}

int main() {
    vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << "Max Water: " << maxArea(heights) << "\n";
    return 0;
}
