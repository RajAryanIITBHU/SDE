/*
 * ============================================================================
 * Concept: Cycle Detection in Directed & Undirected Graphs
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Cycle Detection techniques:
1. Undirected Graph: DFS with parent tracking (if neighbor is visited and `neighbor != parent`, cycle exists) OR Union-Find (if `find(u) == find(v)`, adding edge creates cycle).
2. Directed Graph: DFS with 3-color state / Recursion Stack tracking (0 = unvisited, 1 = visiting, 2 = visited). If neighbor is state 1, cycle exists!
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(V + E) time complexity.
 * - Space Complexity: O(V) recursion stack and color array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Course Schedule I (LC 207).
- Redundant Connection (LC 684).
- Graph Valid Tree (LC 261).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Directed Graph Cycle Detection via 3-color DFS.
 */

#include <iostream>
#include <vector>

using namespace std;

bool dfsCheckCycle(int u, const vector<vector<int>>& adj, vector<int>& state) {
    state[u] = 1; // visiting
    for (int v : adj[u]) {
        if (state[v] == 1) return true; // back-edge detected (cycle)
        if (state[v] == 0 && dfsCheckCycle(v, adj, state)) return true;
    }
    state[u] = 2; // visited
    return false;
}

bool hasCycleDirected(int n, const vector<vector<int>>& adj) {
    vector<int> state(n, 0);
    for (int i = 0; i < n; ++i) {
        if (state[i] == 0 && dfsCheckCycle(i, adj, state)) return true;
    }
    return false;
}

int main() {
    vector<vector<int>> adj = {{1}, {2}, {0}}; // cycle 0->1->2->0
    cout << "Has Cycle: " << (hasCycleDirected(3, adj) ? "Yes" : "No") << "\n";
    return 0;
}
