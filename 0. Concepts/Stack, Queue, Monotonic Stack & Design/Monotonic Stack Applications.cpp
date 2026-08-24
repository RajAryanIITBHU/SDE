/*
 * ============================================================================
 * Concept: Monotonic Stack Applications (Histograms & Water)
 * Subtopic: Stack, Queue, Monotonic Stack & Design
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Advanced applications of monotonic stack to compute 2D areas and trapped volume:
1. Largest Rectangle in Histogram (LC 84): Maintain monotonic increasing stack of heights. When current height is smaller, pop and calculate area `height * (i - stack.top() - 1)`.
2. Trapping Rain Water (LC 42): Monotonic decreasing stack storing bounded troughs.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N) time complexity.
 * - Space Complexity: O(N) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Largest Rectangle in Histogram (LC 84).
- Maximal Rectangle in 2D Binary Grid (LC 85 - convert rows to histogram).
- Trapping Rain Water (LC 42).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Largest Rectangle in Histogram.
2. Maximal Rectangle.
 */

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Largest Rectangle in Histogram (LC 84)
int largestRectangleArea(vector<int>& heights) {
    heights.push_back(0); // Sentinel value
    stack<int> st;
    int max_area = 0;

    for (int i = 0; i < (int)heights.size(); ++i) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            int h = heights[st.top()]; st.pop();
            int w = st.empty() ? i : i - st.top() - 1;
            max_area = max(max_area, h * w);
        }
        st.push(i);
    }
    return max_area;
}

int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3};
    cout << "Max Histogram Area: " << largestRectangleArea(heights) << "\n";
    return 0;
}
