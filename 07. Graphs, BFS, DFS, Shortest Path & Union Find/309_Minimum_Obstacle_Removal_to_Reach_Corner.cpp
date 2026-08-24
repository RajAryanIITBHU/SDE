// Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/

#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (0-1 BFS with Deque)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
1. Initialize dist matrix of size n x m with INT_MAX, dist[0][0] = 0.
2. Deque dq, push_front({0, 0}).
3. While !dq.empty():
     {r, c} = dq.front(), dq.pop_front()
     if r == n - 1 && c == m - 1 return dist[r][c]
     For each (dr, dc) in dirs:
         nr = r + dr, nc = c + dc
         if nr >= 0 && nr < n && nc >= 0 && nc < m:
             weight = grid[nr][nc]
             if dist[r][c] + weight < dist[nr][nc]:
                 dist[nr][nc] = dist[r][c] + weight
                 if weight == 0 -> dq.push_front({nr, nc})
                 else -> dq.push_back({nr, nc})
4. Return dist[n-1][m-1].
*/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;

        dist[0][0] = 0;
        dq.push_front({0, 0});

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            if (r == n - 1 && c == m - 1) {
                return dist[r][c];
            }

            for (auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int weight = grid[nr][nc];

                    if (dist[r][c] + weight < dist[nr][nc]) {
                        dist[nr][nc] = dist[r][c] + weight;

                        if (weight == 0) {
                            dq.push_front({nr, nc});
                        } else {
                            dq.push_back({nr, nc});
                        }
                    }
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};
