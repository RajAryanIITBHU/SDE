/*
 * ============================================================================
 * Concept: State Machine & Stock DP
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Models complex decision state transitions over time.
Stock Trading State Machines maintain states: `held`, `sold` (cooldown), `reset`.
Transitions:
`held = max(held, reset - price)`
`sold = held + price`
`reset = max(reset, sold)`
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(1) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Best Time to Buy and Sell Stock with Cooldown (LC 309).
- Best Time to Buy and Sell Stock with Transaction Fee (LC 714).
- Best Time to Buy and Sell Stock III & IV (LC 123, 188).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Stock with Cooldown (LC 309).
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxProfitCooldown(const vector<int>& prices) {
    int held = INT_MIN, sold = 0, reset = 0;
    for (int p : prices) {
        int prev_sold = sold;
        sold = held + p;
        held = max(held, reset - p);
        reset = max(reset, prev_sold);
    }
    return max(sold, reset);
}

int main() {
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Max Profit (Cooldown): " << maxProfitCooldown(prices) << "\n"; // 3
    return 0;
}
