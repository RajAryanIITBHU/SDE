// Link: https://leetcode.com/problems/maximum-trailing-zeros-in-a-cornered-path/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (2D Prefix Sums of Factors 2 and 5)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
Trailing zeros of a product = min(count of factors of 2, count of factors of 5).
1. Precompute number of factors 2 and 5 for each grid[i][j].
2. Build 4 prefix sum tables:
     top2, top5 (from top down to current cell)
     left2, left5 (from left to right up to current cell)
3. For each cell (i, j), evaluate all 4 possible corner paths passing through (i, j):
     - Top-Left: Top + Left - Cell
     - Top-Right: Top + Right - Cell
     - Bottom-Left: Bottom + Left - Cell
     - Bottom-Right: Bottom + Right - Cell
4. Trailing zeros for each path = min(total2, total5).
5. Return max trailing zeros over all paths.
*/

class Solution {
private:
    pair<int, int> count2and5(int num) {
        int c2 = 0, c5 = 0;
        while (num > 0 && num % 2 == 0) {
            c2++;
            num /= 2;
        }
        while (num > 0 && num % 5 == 0) {
            c5++;
            num /= 5;
        }
        return {c2, c5};
    }

public:
    int maxTrailingZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 2D tables for prefix sums of factors of 2 and 5
        vector<vector<int>> row2(n, vector<int>(m, 0));
        vector<vector<int>> row5(n, vector<int>(m, 0));
        vector<vector<int>> col2(n, vector<int>(m, 0));
        vector<vector<int>> col5(n, vector<int>(m, 0));

        // Factors of cell (i, j)
        vector<vector<int>> val2(n, vector<int>(m, 0));
        vector<vector<int>> val5(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                auto p = count2and5(grid[i][j]);
                val2[i][j] = p.first;
                val5[i][j] = p.second;

                row2[i][j] = (j > 0 ? row2[i][j - 1] : 0) + val2[i][j];
                row5[i][j] = (j > 0 ? row5[i][j - 1] : 0) + val5[i][j];
                col2[i][j] = (i > 0 ? col2[i - 1][j] : 0) + val2[i][j];
                col5[i][j] = (i > 0 ? col5[i - 1][j] : 0) + val5[i][j];
            }
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Top, Bottom, Left, Right segments including cell (i, j)
                int t2 = col2[i][j];
                int t5 = col5[i][j];

                int b2 = col2[n - 1][j] - (i > 0 ? col2[i - 1][j] : 0);
                int b5 = col5[n - 1][j] - (i > 0 ? col5[i - 1][j] : 0);

                int l2 = row2[i][j];
                int l5 = row5[i][j];

                int r2 = row2[i][m - 1] - (j > 0 ? row2[i][j - 1] : 0);
                int r5 = row5[i][m - 1] - (j > 0 ? row5[i][j - 1] : 0);

                int c2 = val2[i][j];
                int c5 = val5[i][j];

                // 1. Top + Left
                ans = max(ans, min(t2 + l2 - c2, t5 + l5 - c5));
                // 2. Top + Right
                ans = max(ans, min(t2 + r2 - c2, t5 + r5 - c5));
                // 3. Bottom + Left
                ans = max(ans, min(b2 + l2 - c2, b5 + l5 - c5));
                // 4. Bottom + Right
                ans = max(ans, min(b2 + r2 - c2, b5 + r5 - c5));
            }
        }

        return ans;
    }
};
