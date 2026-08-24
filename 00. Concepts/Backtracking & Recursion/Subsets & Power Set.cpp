/*
 * ============================================================================
 * Concept: Subsets & Power Set Generation
 * Subtopic: Backtracking & Recursion
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Generates all $2^N$ subsets (power set) of a given set of elements.
At each step $i$, decide whether to include `nums[i]` or exclude `nums[i]`.
Duplicate elements: Sort array first, skip `if (i > start && nums[i] == nums[i-1]) continue`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N * 2^N) time complexity.
 * - Space Complexity: O(N) recursion depth space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Subsets I & II (LC 78, 90).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Subsets II with duplicates.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void backtrackSubsets(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& result) {
    result.push_back(current);
    for (int i = start; i < (int)nums.size(); ++i) {
        if (i > start && nums[i] == nums[i - 1]) continue; // Skip duplicates
        current.push_back(nums[i]);
        backtrackSubsets(i + 1, nums, current, result);
        current.pop_back(); // Backtrack
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> result;
    vector<int> current;
    backtrackSubsets(0, nums, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 2};
    auto res = subsetsWithDup(nums);
    cout << "Total Unique Subsets: " << res.size() << "\n"; // 6
    return 0;
}
