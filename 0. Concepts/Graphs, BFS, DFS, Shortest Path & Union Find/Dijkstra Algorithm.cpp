/*
 * ============================================================================
 * Concept: Dijkstra's Algorithm (Shortest Path in Weighted Graph)
 * Subtopic: Graphs, BFS, DFS, Shortest Path & Union Find
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Finds shortest paths from source node to all other nodes in a weighted graph with NON-NEGATIVE edge weights.
Uses a Min-Heap Priority Queue storing pairs `{dist, node}`. Always extracts node with minimum tentative distance.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O((V + E) log V) time complexity.
 * - Space Complexity: O(V + E) graph and priority queue space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Network Delay Time (LC 743).
- Path with Maximum Probability (LC 1514).
- Path With Minimum Effort (LC 1631).
- Minimum Cost to Make at Least One Valid Path in Grid (LC 1368).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Dijkstra's Algorithm implementation.
 */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

vector<int> dijkstra(int n, const vector<vector<pair<int, int>>>& adj, int src) {
    vector<int> dist(n, INT_MAX);
    // Min-heap storing {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;

        for (auto& edge : adj[u]) {
            int v = edge.first, weight = edge.second;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 4;
    vector<vector<pair<int, int>>> adj(n);
    adj[0].push_back({1, 4});
    adj[0].push_back({2, 1});
    adj[2].push_back({1, 2});
    adj[1].push_back({3, 1});
    adj[2].push_back({3, 5});

    auto dist = dijkstra(n, adj, 0);
    cout << "Shortest dist to 3: " << dist[3] << "\n"; // 0->2->1->3 = 1+2+1=4
    return 0;
}
