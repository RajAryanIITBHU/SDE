/*
 * ============================================================================
 * Concept: Binary Search on Answer Space (Monotonic Predicate)
 * Subtopic: Binary Search & Search on Answer
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Used when the answer space is monotonic (if X works, any X' > X also works, or vice-versa).
Define search range `[low, high]` for the answer, and a boolean helper function `check(mid)` to test feasibility.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N log(Range)) where Range = high - low.
 * - Space Complexity: O(1) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - "Find the minimum maximum..." or "Find the maximum minimum...".
- Koko Eating Bananas, Capacity to Ship Packages within D days, Split Array Largest Sum.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Koko Eating Bananas (LC 875).
2. Capacity To Ship Packages Within D Days (LC 1011).
3. Split Array Largest Sum (LC 410).
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const vector<int>& piles, int speed, int h) {
    int hours = 0;
    for (int p : piles) {
        hours += (p + speed - 1) / speed; // ceil(p / speed)
    }
    return hours <= h;
}

int minEatingSpeed(const vector<int>& piles, int h) {
    int low = 1, high = *max_element(piles.begin(), piles.end());
    int ans = high;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (check(piles, mid, h)) {
            ans = mid;
            high = mid - 1; // Try smaller speed
        } else {
            low = mid + 1;  // Need faster speed
        }
    }
    return ans;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    cout << "Min Eating Speed: " << minEatingSpeed(piles, 8) << "\n";
    return 0;
}
