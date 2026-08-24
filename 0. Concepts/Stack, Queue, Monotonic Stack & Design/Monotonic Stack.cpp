/*
 * ============================================================================
 * Concept: Monotonic Stack (Next/Prev Greater/Smaller)
 * Subtopic: Stack, Queue, Monotonic Stack & Design
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * A stack that maintains elements in monotonically increasing or decreasing order.
Used to find the Next Greater Element, Next Smaller Element, Previous Greater Element, or Previous Smaller Element in O(N) total time.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) - each element is pushed and popped at most once.
 * - Space Complexity: O(N) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Next Greater Element I & II (LC 496, 503).
- Daily Temperatures (LC 739).
- Online Stock Span (LC 901).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Next Greater Element I & II.
2. Daily Temperatures.
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Daily Temperatures (LC 739) - Next Greater Element
vector<int> dailyTemperatures(const vector<int>& temp) {
    int n = temp.size();
    vector<int> ans(n, 0);
    stack<int> st; // stores indices

    for (int i = 0; i < n; ++i) {
        while (!st.empty() && temp[i] > temp[st.top()]) {
            int idx = st.top(); st.pop();
            ans[idx] = i - idx;
        }
        st.push(i);
    }
    return ans;
}

int main() {
    vector<int> temps = {73, 74, 75, 71, 69, 72, 76, 73};
    auto res = dailyTemperatures(temps);
    cout << "Days to warmer temp: ";
    for (int x : res) cout << x << " ";
    cout << "\n";
    return 0;
}
