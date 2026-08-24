// Link: https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/

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
Grid directions: 1 -> right (0,1), 2 -> left (0,-1), 3 -> down (1,0), 4 -> up (-1,0)
1. Initialize cost matrix with INT_MAX, cost[0][0] = 0.
2. Deque dq, push {0, 0}.
3. While !dq.empty():
     {r, c} = dq.front(), dq.pop_front()
     if r == n - 1 && c == m - 1 return cost[r][c]
     For dirIdx from 1 to 4:
         weight = (grid[r][c] == dirIdx) ? 0 : 1
         nr = r + dr, nc = c + dc
         if nr >= 0 && nr < n && nc >= 0 && nc < m:
             if cost[r][c] + weight < cost[nr][nc]:
                 cost[nr][nc] = cost[r][c] + weight
                 if weight == 0 -> dq.push_front({nr, nc})
                 else -> dq.push_back({nr, nc})
4. Return cost[n-1][m-1].
*/

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        // 1-indexed directions: 1: right, 2: left, 3: down, 4: up
        vector<pair<int, int>> dirs = {{0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        deque<pair<int, int>> dq;

        cost[0][0] = 0;
        dq.push_front({0, 0});

        while (!dq.empty()) {
            auto [r, c] = dq.front();
            dq.pop_front();

            if (r == n - 1 && c == m - 1) {
                return cost[r][c];
            }

            for (int dirIdx = 1; dirIdx <= 4; dirIdx++) {
                int nr = r + dirs[dirIdx].first;
                int nc = c + dirs[dirIdx].second;
                int weight = (grid[r][c] == dirIdx) ? 0 : 1;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    if (cost[r][c] + weight < cost[nr][nc]) {
                        cost[nr][nc] = cost[r][c] + weight;

                        if (weight == 0) {
                            dq.push_front({nr, nc}); // 0-cost edge to front
                        } else {
                            dq.push_back({nr, nc});  // 1-cost edge to back
                        }
                    }
                }
            }
        }

        return cost[n - 1][m - 1];
    }
};
