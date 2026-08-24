/*
 * ============================================================================
 * Concept: Multi-Source BFS
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Pushes ALL source nodes into the BFS queue initially before starting step-by-step level expansion.
Computes minimum distance from ANY source to all target cells simultaneously in a single pass.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(R * C) time complexity.
 * - Space Complexity: O(R * C) queue space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Rotting Oranges (LC 994).
- 01 Matrix (LC 542 - Distance from nearest 0).
- As Far from Land as Possible (LC 1162).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Rotting Oranges.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int orangesRotting(vector<vector<int>>& grid) {
    int rows = grid.size(), cols = grid[0].size();
    queue<pair<int, int>> q;
    int fresh = 0;

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            if (grid[r][c] == 2) q.push({r, c});
            else if (grid[r][c] == 1) fresh++;
        }
    }

    if (fresh == 0) return 0;
    int minutes = 0;
    vector<pair<int, int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    while (!q.empty() && fresh > 0) {
        minutes++;
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto [r, c] = q.front(); q.pop();
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && grid[nr][nc] == 1) {
                    grid[nr][nc] = 2;
                    fresh--;
                    q.push({nr, nc});
                }
            }
        }
    }
    return fresh == 0 ? minutes : -1;
}

int main() {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    cout << "Minutes to rot: " << orangesRotting(grid) << "\n";
    return 0;
}
