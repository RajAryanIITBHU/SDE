// Link: https://leetcode.com/problems/max-area-of-island/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Grid DFS Area Accumulation)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m) recursion stack
/*
PSEUDOCODE:
1. Helper getArea(r, c):
     if r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0 return 0
     grid[r][c] = 0 // Sink visited land
     area = 1
     For each (dr, dc) in dirs:
         area += getArea(r + dr, c + dc)
     return area
2. maxArea = 0.
3. For r from 0 to n-1:
     For c from 0 to m-1:
         if grid[r][c] == 1:
             maxArea = max(maxArea, getArea(r, c))
4. Return maxArea.
*/

class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    int getArea(vector<vector<int>>& grid, int r, int c, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == 0) {
            return 0;
        }

        grid[r][c] = 0; // Mark visited
        int area = 1;

        for (auto& dir : dirs) {
            area += getArea(grid, r + dir.first, c + dir.second, n, m);
        }

        return area;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxArea = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    maxArea = max(maxArea, getArea(grid, i, j, n, m));
                }
            }
        }

        return maxArea;
    }
};
