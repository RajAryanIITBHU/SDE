// Link: https://leetcode.com/problems/rotting-oranges/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Multi-Source BFS)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
1. Count fresh oranges freshCount.
2. Push all rotten oranges (grid[r][c] == 2) into queue q.
3. If freshCount == 0 return 0.
4. minutes = 0.
5. While !q.empty() && freshCount > 0:
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         {r, c} = q.front(), q.pop()
         For each (dr, dc) in dirs:
             nr = r + dr, nc = c + dc
             if nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1:
                 grid[nr][nc] = 2 // Rot the fresh orange
                 freshCount--
                 q.push({nr, nc})
     minutes++
6. Return freshCount == 0 ? minutes : -1.
*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                } else if (grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int minutes = 0;

        while (!q.empty() && freshCount > 0) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        freshCount--;
                        q.push({nr, nc});
                    }
                }
            }

            minutes++;
        }

        return (freshCount == 0) ? minutes : -1;
    }
};
