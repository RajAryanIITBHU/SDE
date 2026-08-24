/*
 * ============================================================================
 * Concept: Kadane's Algorithm (Max Subarray Sum)
 * Subtopic: Arrays, Hashing & Prefix Sum
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Kadane's algorithm finds the contiguous subarray within a 1D numerical array that has the maximum sum.
It works by maintaining a running sum (`current_sum`) and updating the global maximum (`max_sum`).
At each index `i`, we decide whether to add `arr[i]` to `current_sum` or start a new subarray from `arr[i]`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - single pass over the array of size N.
 * - Space Complexity: O(1) - auxiliary space (stores only running sum variables).
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Problem asks for contiguous subarray with maximum/minimum sum.
- Input contains negative and positive numbers.
- Dynamic programming state reduction: dp[i] = max(nums[i], dp[i-1] + nums[i]).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Print the actual Subarray (maintain start, end, and temp_start pointers).
2. Minimum Subarray Sum (invert logic with min()).
3. Maximum Product Subarray (maintain both max_prod and min_prod to handle negative numbers).
4. Circular Subarray Sum (max(Kadane, Total_Sum - Min_Kadane)).
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Standard Kadane's Algorithm
int maxSubArray(const vector<int>& nums) {
    int max_sum = nums[0];
    int current_sum = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        current_sum = max(nums[i], current_sum + nums[i]);
        max_sum = max(max_sum, current_sum);
    }
    return max_sum;
}

// Variation: Kadane's with Subarray Index Tracking
pair<int, pair<int, int>> maxSubArrayWithIndices(const vector<int>& nums) {
    int max_sum = nums[0];
    int current_sum = nums[0];
    int start = 0, end = 0, temp_start = 0;

    for (int i = 1; i < (int)nums.size(); ++i) {
        if (nums[i] > current_sum + nums[i]) {
            current_sum = nums[i];
            temp_start = i;
        } else {
            current_sum += nums[i];
        }

        if (current_sum > max_sum) {
            max_sum = current_sum;
            start = temp_start;
            end = i;
        }
    }
    return {max_sum, {start, end}};
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Max Subarray Sum: " << maxSubArray(nums) << "\n";
    auto res = maxSubArrayWithIndices(nums);
    cout << "Subarray Range: [" << res.second.first << ", " << res.second.second << "]\n";
    return 0;
}
