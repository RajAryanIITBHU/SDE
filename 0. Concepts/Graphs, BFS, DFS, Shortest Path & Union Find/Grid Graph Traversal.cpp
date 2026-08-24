/*
 * ============================================================================
 * Concept: Grid Graph Traversal (BFS & DFS)
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Explores 2D grid graphs where cells are nodes and adjacent cells (4-directional or 8-directional) are edges.
Uses DFS (recursion/stack) for connected component counting/areas and BFS for shortest path steps.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(R * C) visits each grid cell constant times.
 * - Space Complexity: O(R * C) space for visited grid / queue / recursion stack.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Number of Islands (LC 200).
- Max Area of Island (LC 695).
- Flood Fill (LC 733).
- Pacific Atlantic Water Flow (LC 417).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Number of Islands (DFS Flood Fill).
 */

#include <iostream>
#include <vector>

using namespace std;

void dfs(vector<vector<char>>& grid, int r, int c) {
    int rows = grid.size(), cols = grid[0].size();
    if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1') return;
    grid[r][c] = '0'; // mark visited
    dfs(grid, r + 1, c);
    dfs(grid, r - 1, c);
    dfs(grid, r, c + 1);
    dfs(grid, r, c - 1);
}

int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int count = 0;
    for (int r = 0; r < (int)grid.size(); ++r) {
        for (int c = 0; c < (int)grid[0].size(); ++c) {
            if (grid[r][c] == '1') {
                count++;
                dfs(grid, r, c);
            }
        }
    }
    return count;
}

int main() {
    vector<vector<char>> grid = {
        {'1', '1', '0', '0'},
        {'1', '1', '0', '0'},
        {'0', '0', '1', '0'}
    };
    cout << "Islands Count: " << numIslands(grid) << "\n";
    return 0;
}
