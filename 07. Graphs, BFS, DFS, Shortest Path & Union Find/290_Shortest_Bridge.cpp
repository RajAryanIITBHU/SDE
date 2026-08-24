// Link: https://leetcode.com/problems/shortest-bridge/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (DFS 1st Island Identification + Multi-Source BFS)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. Find the first cell with grid[r][c] == 1.
2. DFS from that cell to find all connected land of Island 1, mark as 2, and add coordinates to BFS queue q.
3. Multi-source BFS from Island 1 to reach Island 2:
     steps = 0
     While !q.empty():
         For each node in current level:
             For each 4-direction neighbor:
                 if neighbor == 1 return steps (Island 2 reached!)
                 if neighbor == 0:
                     mark 2, push to q
         steps++
4. Return steps.
*/

class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& grid, int r, int c, int n, queue<pair<int, int>>& q) {
        if (r < 0 || r >= n || c < 0 || c >= n || grid[r][c] != 1) {
            return;
        }

        grid[r][c] = 2; // Mark island 1
        q.push({r, c});

        for (auto& dir : dirs) {
            dfs(grid, r + dir.first, c + dir.second, n, q);
        }
    }

public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, int>> q;
        bool foundFirstIsland = false;

        // Step 1: Find and mark first island with DFS
        for (int i = 0; i < n && !foundFirstIsland; i++) {
            for (int j = 0; j < n && !foundFirstIsland; j++) {
                if (grid[i][j] == 1) {
                    dfs(grid, i, j, n, q);
                    foundFirstIsland = true;
                }
            }
        }

        // Step 2: Expand using BFS until reaching the second island
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& dir : dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                        if (grid[nr][nc] == 1) {
                            return steps; // Reached second island!
                        }
                        if (grid[nr][nc] == 0) {
                            grid[nr][nc] = 2; // Mark visited
                            q.push({nr, nc});
                        }
                    }
                }
            }

            steps++;
        }

        return steps;
    }
};
