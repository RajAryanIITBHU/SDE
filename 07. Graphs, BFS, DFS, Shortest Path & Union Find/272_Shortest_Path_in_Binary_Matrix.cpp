// Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (8-Directional BFS)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. If grid[0][0] != 0 || grid[n-1][n-1] != 0 return -1.
2. If n == 1 return 1.
3. Initialize queue<pair<int, int>> q, push {0, 0}, grid[0][0] = 1 (mark distance/visited), dist = 1.
4. While !q.empty():
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         {r, c} = q.front(), q.pop()
         if r == n - 1 && c == n - 1 return dist
         For each 8-directional neighbor (nr, nc):
             if nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0:
                 grid[nr][nc] = 1
                 q.push({nr, nc})
     dist++
5. Return -1.
*/

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;
        if (n == 1) return 1;

        vector<pair<int, int>> dirs = {
            {-1, -1}, {-1, 0}, {-1, 1},
            {0, -1},           {0, 1},
            {1, -1},  {1, 0},  {1, 1}
        };

        queue<pair<int, int>> q;
        q.push({0, 0});
        grid[0][0] = 1; // Mark visited

        int pathLen = 1;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                if (r == n - 1 && c == n - 1) {
                    return pathLen;
                }

                for (auto& dir : dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                        grid[nr][nc] = 1; // Visited
                        q.push({nr, nc});
                    }
                }
            }

            pathLen++;
        }

        return -1;
    }
};
