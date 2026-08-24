// Link: https://leetcode.com/problems/number-of-islands/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Grid DFS Traversal)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m) recursion stack
/*
PSEUDOCODE:
1. Helper dfs(r, c):
     if r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '0' return
     grid[r][c] = '0' // Sink the island
     For each direction (dr, dc):
         dfs(r + dr, c + dc)
2. islands = 0.
3. For r from 0 to n-1:
     For c from 0 to m-1:
         if grid[r][c] == '1':
             islands++
             dfs(r, c)
4. Return islands.
*/

class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& grid, int r, int c, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || grid[r][c] == '0') {
            return;
        }

        grid[r][c] = '0'; // Mark visited in-place

        for (auto& dir : dirs) {
            dfs(grid, r + dir.first, c + dir.second, n, m);
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int islands = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j, n, m);
                }
            }
        }

        return islands;
    }
};
