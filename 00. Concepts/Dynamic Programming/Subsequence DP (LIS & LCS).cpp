/*
 * ============================================================================
 * Concept: Subsequence DP (LIS & LCS)
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Core subsequence dynamic programming patterns:
1. Longest Common Subsequence (LCS): `dp[i][j]` matches `s1[i-1]` and `s2[j-1]`.
2. Longest Increasing Subsequence (LIS): Can be solved in O(N^2) via DP or O(N log N) via Binary Search (`std::lower_bound` on `tails` array).
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: LCS: O(M * N), LIS: O(N log N).
 * - Space Complexity: LCS: O(N) space, LIS: O(N) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Longest Common Subsequence (LC 1143).
- Longest Increasing Subsequence (LC 300).
- Edit Distance (LC 72).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. LIS in O(N log N) using Binary Search.
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// LIS in O(N log N)
int lengthOfLIS(const vector<int>& nums) {
    vector<int> tails;
    for (int num : nums) {
        auto it = lower_bound(tails.begin(), tails.end(), num);
        if (it == tails.end()) tails.push_back(num);
        else *it = num;
    }
    return tails.size();
}

int main() {
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS Length: " << lengthOfLIS(nums) << "\n"; // 4 (2,3,7,101)
    return 0;
}
