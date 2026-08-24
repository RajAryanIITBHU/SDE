/*
 * ============================================================================
 * Concept: Bitmask Dynamic Programming
 * Subtopic: Dynamic Programming
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Uses an integer bitmask `mask` to represent subset inclusion states (for small N <= 20).
Bit operations:
- Check element i: `(mask & (1 << i)) != 0`
- Set element i: `mask | (1 << i)`
- Toggle element i: `mask ^ (1 << i)`
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N^2 * 2^N) or O(N * 2^N) time complexity.
 * - Space Complexity: O(N * 2^N) space complexity.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Shortest Path Visiting All Nodes (LC 847).
- Partition to K Equal Sum Subsets (LC 698).
- Traveling Salesperson Problem (TSP).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Shortest Path Visiting All Nodes (LC 847).
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int shortestPathLength(vector<vector<int>>& graph) {
    int n = graph.size();
    if (n == 1) return 0;

    int targetMask = (1 << n) - 1;
    queue<pair<int, int>> q; // {node, mask}
    vector<vector<bool>> visited(n, vector<bool>(1 << n, false));

    for (int i = 0; i < n; ++i) {
        q.push({i, 1 << i});
        visited[i][1 << i] = true;
    }

    int steps = 0;
    while (!q.empty()) {
        int sz = q.size();
        for (int i = 0; i < sz; ++i) {
            auto [u, mask] = q.front(); q.pop();
            if (mask == targetMask) return steps;

            for (int v : graph[u]) {
                int nextMask = mask | (1 << v);
                if (!visited[v][nextMask]) {
                    visited[v][nextMask] = true;
                    q.push({v, nextMask});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    vector<vector<int>> graph = {{1,2,3},{0},{0},{0}};
    cout << "Shortest Path All Nodes: " << shortestPathLength(graph) << "\n"; // 4
    return 0;
}
