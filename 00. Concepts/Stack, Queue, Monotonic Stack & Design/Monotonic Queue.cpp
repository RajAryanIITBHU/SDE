/*
 * ============================================================================
 * Concept: Monotonic Queue (Sliding Window Maximum)
 * Subtopic: Stack, Queue, Monotonic Stack & Design
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Maintains elements in a Double-Ended Queue (`std::deque`) in monotonically decreasing order.
Front of deque always contains max element of current sliding window.
When sliding window right:
1. Remove elements from back of deque smaller than `nums[i]`.
2. Push `i` onto back of deque.
3. Remove element from front if it falls outside window `front <= i - K`.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(K) space for deque of size K.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Sliding Window Maximum (LC 239).
- Constrained Subsequence Sum (LC 1425).
- Shortest Subarray with Sum at Least K (LC 862).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Sliding Window Maximum (LC 239).
 */

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxSlidingWindow(const vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;

    for (int i = 0; i < (int)nums.size(); ++i) {
        // 1. Remove out-of-window elements from front
        if (!dq.empty() && dq.front() == i - k) dq.pop_front();
        // 2. Remove smaller elements from back
        while (!dq.empty() && nums[dq.back()] < nums[i]) dq.pop_back();
        // 3. Add current element index
        dq.push_back(i);
        // 4. Record result
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    auto res = maxSlidingWindow(nums, 3);
    cout << "Window Maxes: ";
    for (int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
