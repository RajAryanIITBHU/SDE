/*
 * ============================================================================
 * Concept: Shortest Path in Unweighted Graph (BFS)
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * BFS naturally finds the shortest path in unweighted graphs or grids because it explores nodes in increasing order of distance from source.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(V + E) time complexity.
 * - Space Complexity: O(V) queue and distance array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Shortest Path in Binary Matrix (LC 1091).
- Word Ladder (LC 127).
- Open the Lock (LC 752).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Shortest Path in Binary Matrix.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] != 0 || grid[n - 1][n - 1] != 0) return -1;

    queue<pair<int, int>> q;
    q.push({0, 0});
    grid[0][0] = 1; // distance

    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

    while (!q.empty()) {
        auto [r, c] = q.front(); q.pop();
        int dist = grid[r][c];
        if (r == n - 1 && c == n - 1) return dist;

        for (auto [dr, dc] : dirs) {
            int nr = r + dr, nc = c + dc;
            if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 0) {
                grid[nr][nc] = dist + 1;
                q.push({nr, nc});
            }
        }
    }
    return -1;
}

int main() {
    vector<vector<int>> grid = {{0, 1}, {1, 0}};
    cout << "Shortest Path: " << shortestPathBinaryMatrix(grid) << "\n";
    return 0;
}
