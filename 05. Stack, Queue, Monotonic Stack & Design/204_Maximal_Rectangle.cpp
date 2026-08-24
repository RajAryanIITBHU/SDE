// Link: https://leetcode.com/problems/maximal-rectangle/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Row-by-Row Histogram + Monotonic Stack)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(m)
/*
PSEUDOCODE:
1. Maintain heights array of size m initialized to 0.
2. For each row:
     For each col:
         if matrix[row][col] == '1' -> heights[col]++
         else -> heights[col] = 0
     maxArea = max(maxArea, largestRectangleInHistogram(heights))
3. Return maxArea.
*/

class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int m = heights.size();
        stack<int> st;
        int maxArea = 0;

        for (int i = 0; i <= m; i++) {
            int currentHeight = (i == m) ? 0 : heights[i];

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

public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;

        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0);
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }

            maxArea = max(maxArea, largestRectangleArea(heights));
        }

        return maxArea;
    }
};
