// Link: https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Increasing Stack - Single Pass)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain stack<int> st storing indices of increasing heights.
2. Initialize maxArea = 0.
3. For i from 0 to n:
     currentHeight = (i == n) ? 0 : heights[i]
     While !st.empty() && currentHeight < heights[st.top()]:
         h = heights[st.top()], st.pop()
         w = st.empty() ? i : (i - st.top() - 1)
         maxArea = max(maxArea, h * w)
     st.push(i)
4. Return maxArea.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st; // Stores indices
        int maxArea = 0;

        for (int i = 0; i <= n; i++) {
            int currentHeight = (i == n) ? 0 : heights[i];

            while (!st.empty() && currentHeight < heights[st.top()]) {
                int h = heights[st.top()];
                st.pop();

                int w = st.empty() ? i : (i - st.top() - 1);
                maxArea = max(maxArea, h * w);
            }

            st.push(i);
        }

        return maxArea;
    }
};
