/*
 * ============================================================================
 * Concept: Bipartite Graph Verification (2-Coloring)
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * A graph is bipartite if its vertices can be partitioned into two sets such that every edge connects vertices in different sets.
Equivalent to checking if the graph contains NO odd-length cycles.
Algorithm: Color graph nodes using 2 colors (1 and -1) via BFS/DFS. If neighbor has same color, graph is NOT bipartite!
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(V + E) time complexity.
 * - Space Complexity: O(V) color array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Is Graph Bipartite? (LC 785).
- Possible Bipartition (LC 886).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. 2-Coloring BFS Bipartite Check.
 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isBipartite(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> color(n, 0); // 0: uncolored, 1 & -1: colors

    for (int i = 0; i < n; ++i) {
        if (color[i] != 0) continue;
        queue<int> q;
        q.push(i);
        color[i] = 1;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (int v : graph[u]) {
                if (color[v] == 0) {
                    color[v] = -color[u];
                    q.push(v);
                } else if (color[v] == color[u]) {
                    return false;
                }
            }
        }
    }
    return true;
}

int main() {
    vector<vector<int>> g = {{1, 3}, {0, 2}, {1, 3}, {0, 2}}; // 4-cycle -> Bipartite
    cout << "Is Bipartite: " << (isBipartite(g) ? "Yes" : "No") << "\n";
    return 0;
}
