/*
 * ============================================================================
 * Concept: Sliding Window (Fixed Size)
 * Subtopic: Two Pointers, Sliding Window & Strings
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Maintains a window of fixed length `K` that slides across the array from left to right.
We compute the initial window result for `[0 ... K-1]`, then slide the window by adding `nums[i]` and subtracting `nums[i-K]`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - single pass.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Subarray / Substring of fixed length K.
- Max/Min average, sum, or vowel count in subarray of size K.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Maximum Average Subarray I (LC 643).
2. Maximum Number of Vowels in a Substring of Given Length (LC 1456).
3. Find All Anagrams in a String (Fixed window of size = p.length()).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Maximum Average Subarray I (LC 643)
double findMaxAverage(const vector<int>& nums, int k) {
    double current_sum = 0;
    for (int i = 0; i < k; ++i) current_sum += nums[i];
    double max_sum = current_sum;

    for (size_t i = k; i < nums.size(); ++i) {
        current_sum += nums[i] - nums[i - k];
        max_sum = max(max_sum, current_sum);
    }
    return max_sum / k;
}

int main() {
    vector<int> nums = {1, 12, -5, -6, 50, 3};
    cout << "Max Average (k=4): " << findMaxAverage(nums, 4) << "\n";
    return 0;
}
