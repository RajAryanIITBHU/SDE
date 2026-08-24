/*
 * ============================================================================
 * Concept: Bellman-Ford & SPFA Shortest Path
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Bellman-Ford finds shortest paths from source to all nodes in graphs with NEGATIVE edge weights, and detects negative cycles.
Relaxes all E edges V-1 times. Run 1 additional relaxation pass: if any edge can still be relaxed, a negative cycle exists!
SPFA (Shortest Path Faster Algorithm) optimizes Bellman-Ford using a queue of relaxed nodes.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(V * E) time complexity.
 * - Space Complexity: O(V) distance array space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Cheapest Flights Within K Stops (LC 787 - Bellman-Ford restricted to K relaxations).
- Graphs with negative weights or negative cycles.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Bellman-Ford Algorithm with Negative Cycle Detection.
 */

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

struct Edge {
    int u, v, weight;
};

bool bellmanFord(int n, const vector<Edge>& edges, int src, vector<int>& dist) {
    dist.assign(n, INT_MAX);
    dist[src] = 0;

    for (int i = 1; i <= n - 1; ++i) {
        for (const auto& e : edges) {
            if (dist[e.u] != INT_MAX && dist[e.u] + e.weight < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.weight;
            }
        }
    }

    // Negative cycle check
    for (const auto& e : edges) {
        if (dist[e.u] != INT_MAX && dist[e.u] + e.weight < dist[e.v]) {
            return false; // Negative cycle present
        }
    }
    return true;
}

int main() {
    vector<Edge> edges = {{0, 1, 1}, {1, 2, -1}, {2, 0, -1}}; // Negative cycle
    vector<int> dist;
    bool valid = bellmanFord(3, edges, 0, dist);
    cout << "Valid (No Neg Cycle): " << (valid ? "Yes" : "No") << "\n";
    return 0;
}
