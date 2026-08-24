/*
 * ============================================================================
 * Concept: Minimum Spanning Tree (Kruskal & Prim)
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Connects all V vertices in a weighted undirected graph with V-1 edges such that total edge weight is minimized.
1. Kruskal's Algorithm: Sort all edges by weight, iterate edges, and add to MST if endpoints are not connected (using DSU).
2. Prim's Algorithm: Start from node 0, add adjacent edges to Min-Heap, pick smallest edge leading to an unvisited node.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: Kruskal: O(E log E), Prim: O(E log V).
 * - Space Complexity: O(V + E) space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Min Cost to Connect All Points (LC 1584).
- Connecting cities with minimum cost.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Kruskal's MST Algorithm using DSU.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(const Edge& other) const { return weight < other.weight; }
};

int kruskalMST(int n, vector<Edge>& edges) {
    sort(edges.begin(), edges.end());
    vector<int> parent(n);
    iota(parent.begin(), parent.end(), 0);

    auto find = [&](auto& self, int i) -> int {
        return parent[i] == i ? i : parent[i] = self(self, parent[i]);
    };

    int total_weight = 0, edges_count = 0;
    for (const auto& e : edges) {
        int root_u = find(find, e.u);
        int root_v = find(find, e.v);
        if (root_u != root_v) {
            parent[root_u] = root_v;
            total_weight += e.weight;
            edges_count++;
            if (edges_count == n - 1) break;
        }
    }
    return total_weight;
}

int main() {
    vector<Edge> edges = {{0,1,1}, {0,2,3}, {1,2,2}, {1,3,4}, {2,3,5}};
    cout << "MST Weight: " << kruskalMST(4, edges) << "\n"; // 1 + 2 + 4 = 7
    return 0;
}
