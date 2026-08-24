/*
 * ============================================================================
 * Concept: Permutations Generation
 * Subtopic: Backtracking & Recursion
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Generates all $N!$ distinct ordered arrangements of elements.
Uses a `visited` boolean array or in-place element swapping.
Handling duplicates: Sort array, skip `if (i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N * N!) time complexity.
 * - Space Complexity: O(N) recursion stack and visited array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Permutations I & II (LC 46, 47).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Permutations I (LC 46).
 */

#include <iostream>
#include <vector>

using namespace std;

void backtrackPermute(vector<int>& nums, vector<bool>& visited, vector<int>& current, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (visited[i]) continue;
        visited[i] = true;
        current.push_back(nums[i]);
        backtrackPermute(nums, visited, current, result);
        current.pop_back();
        visited[i] = false;
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> visited(nums.size(), false);
    backtrackPermute(nums, visited, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    auto res = permute(nums);
    cout << "Total Permutations: " << res.size() << "\n"; // 6
    return 0;
}
