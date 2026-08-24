/*
 * ============================================================================
 * Concept: Lower Bound & Upper Bound (Binary Search Boundaries)
 * Subtopic: Binary Search & Search on Answer
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Lower Bound: Finds the FIRST index where `nums[i] >= target` (or `std::lower_bound`).
Upper Bound: Finds the FIRST index where `nums[i] > target` (or `std::upper_bound`).
Used to find first/last occurrences or target range size `upper_bound - lower_bound`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(log N) time complexity.
 * - Space Complexity: O(1) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Search Insert Position (LC 35).
- Find First and Last Position of Element in Sorted Array (LC 34).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. `lower_bound`: `if (nums[mid] >= target) high = mid; else low = mid + 1;`
2. `upper_bound`: `if (nums[mid] > target) high = mid; else low = mid + 1;`
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findLowerBound(const vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] >= target) high = mid;
        else low = mid + 1;
    }
    return low;
}

int findUpperBound(const vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] > target) high = mid;
        else low = mid + 1;
    }
    return low;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int lb = findLowerBound(nums, 8);
    int ub = findUpperBound(nums, 8);
    cout << "Range of 8: [" << lb << ", " << ub - 1 << "]\n";
    return 0;
}
