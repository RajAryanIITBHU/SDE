/*
 * ============================================================================
 * Concept: Pruning & Branch-and-Bound Optimizations
 * Subtopic: Backtracking & Recursion
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Accelerates backtracking by pruning unpromising recursion branches early:
1. Sort elements descending before searching to fail fast on large values.
2. Check capacity / target sum feasibility before entering child recursive calls.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: Significantly reduces search space from O(K^N) to manageable depth.
 * - Space Complexity: O(N) recursion stack.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Matchsticks to Square (LC 473).
- Partition to K Equal Sum Subsets (LC 698).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Matchsticks to Square (LC 473).
 */

#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

bool backtrackMatch(int idx, vector<int>& matchsticks, vector<int>& sides, int target) {
    if (idx == (int)matchsticks.size()) return true;
    for (int i = 0; i < 4; ++i) {
        if (sides[i] + matchsticks[idx] > target) continue; // Prune branch
        sides[i] += matchsticks[idx];
        if (backtrackMatch(idx + 1, matchsticks, sides, target)) return true;
        sides[i] -= matchsticks[idx]; // Backtrack
        if (sides[i] == 0) break; // Prune duplicate empty side
    }
    return false;
}

bool makesquare(vector<int>& matchsticks) {
    int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);
    if (sum % 4 != 0) return false;
    sort(matchsticks.rbegin(), matchsticks.rend()); // Sort descending to fail fast
    vector<int> sides(4, 0);
    return backtrackMatch(0, matchsticks, sides, sum / 4);
}

int main() {
    vector<int> match = {1, 1, 2, 2, 2};
    cout << "Can Make Square: " << (makesquare(match) ? "Yes" : "No") << "\n";
    return 0;
}
