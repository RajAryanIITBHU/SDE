// Link: https://leetcode.com/problems/island-perimeter/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Grid Cell Edge Counting)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize perimeter = 0.
2. For r from 0 to n-1:
     For c from 0 to m-1:
         if grid[r][c] == 1:
             perimeter += 4
             if r > 0 && grid[r - 1][c] == 1 -> perimeter -= 2 (shared horizontal edge)
             if c > 0 && grid[r][c - 1] == 1 -> perimeter -= 2 (shared vertical edge)
3. Return perimeter.
*/

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int perimeter = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;

                    // Subtract 2 for every shared edge with adjacent land
                    if (i > 0 && grid[i - 1][j] == 1) perimeter -= 2;
                    if (j > 0 && grid[i][j - 1] == 1) perimeter -= 2;
                }
            }
        }

        return perimeter;
    }
};
