// Link: https://leetcode.com/problems/as-far-from-land-as-possible/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Multi-Source BFS from all Land Cells)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. Push all land cells (grid[r][c] == 1) into queue q.
2. If all cells are land or all water (q.size() == 0 || q.size() == n*n) return -1.
3. maxDist = -1.
4. While !q.empty():
     levelSize = q.size()
     maxDist++
     For i from 0 to levelSize - 1:
         {r, c} = q.front(), q.pop()
         For each (dr, dc) in dirs:
             nr = r + dr, nc = c + dc
             if nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0:
                 grid[nr][nc] = 1 // Mark visited
                 q.push({nr, nc})
5. Return maxDist.
*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                }
            }
        }

        // If no land or all land
        if (q.empty() || (int)q.size() == n * n) {
            return -1;
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int dist = -1;

        while (!q.empty()) {
            int sz = q.size();
            dist++;

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1; // Visited
                        q.push({nr, nc});
                    }
                }
            }
        }

        return dist;
    }
};
