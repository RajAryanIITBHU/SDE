// Link: https://leetcode.com/problems/01-matrix/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Multi-Source BFS from all 0s)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
1. Initialize dist matrix of size n x m with -1.
2. Initialize queue<pair<int, int>> q.
3. For r from 0 to n-1:
     For c from 0 to m-1:
         if mat[r][c] == 0:
             dist[r][c] = 0
             q.push({r, c})
4. While !q.empty():
     {r, c} = q.front(), q.pop()
     For each (dr, dc) in dirs:
         nr = r + dr, nc = c + dc
         if nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1:
             dist[nr][nc] = dist[r][c] + 1
             q.push({nr, nc})
5. Return dist.
*/

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, -1));
        queue<pair<int, int>> q;

        // Push all 0 cells to start multi-source BFS
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && dist[nr][nc] == -1) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        return dist;
    }
};
