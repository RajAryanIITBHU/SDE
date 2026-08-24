/*
 * ============================================================================
 * Concept: Combination Sum Patterns
 * Subtopic: Backtracking & Recursion
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Finds target combinations:
- Combination Sum I (LC 39): Unlimited element reuse (`backtrack(i)`).
- Combination Sum II (LC 40): Single element use (`backtrack(i+1)` with duplicate skip).
- Combination Sum III (LC 216): Combination of K numbers summing to N.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(2^Target) exponential time.
 * - Space Complexity: O(Target) recursion stack space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Combination Sum I, II, III (LC 39, 40, 216).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Combination Sum I.
 */

#include <iostream>
#include <vector>

using namespace std;

void backtrackCombo(int start, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }
    for (int i = start; i < (int)candidates.size(); ++i) {
        if (candidates[i] > target) continue;
        current.push_back(candidates[i]);
        backtrackCombo(i, candidates, target - candidates[i], current, result); // reuse index i
        current.pop_back();
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    backtrackCombo(0, candidates, target, current, result);
    return result;
}

int main() {
    vector<int> cand = {2, 3, 6, 7};
    auto res = combinationSum(cand, 7);
    cout << "Combinations Count: " << res.size() << "\n"; // 2 ([7], [2,2,3])
    return 0;
}
