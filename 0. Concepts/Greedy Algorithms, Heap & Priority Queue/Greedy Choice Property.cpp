/*
 * ============================================================================
 * Concept: Greedy Choice Property
 * Subtopic: Greedy Algorithms, Heap & Priority Queue
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Greedy algorithms make locally optimal choices at each step to reach a global optimum.
Requires proving that a greedy choice never hinders optimal resolution.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) or O(N log N) time complexity.
 * - Space Complexity: O(1) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Jump Game I & II (LC 55, 45).
- Gas Station (LC 134).
- Partition Labels (LC 763).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Jump Game I (LC 55).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canJump(const vector<int>& nums) {
    int maxReach = 0;
    for (int i = 0; i < (int)nums.size(); ++i) {
        if (i > maxReach) return false;
        maxReach = max(maxReach, i + nums[i]);
    }
    return true;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << "Can Jump: " << (canJump(nums) ? "Yes" : "No") << "\n";
    return 0;
}
