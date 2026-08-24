// Link: https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Min-Heap Dijkstra)
// ==========================================
// Time Complexity  : O(E log V)
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. dist array of size V initialized to INT_MAX. dist[src] = 0.
2. Min-heap pq storing {distance, vertex}.
3. pq.push({0, src}).
4. While !pq.empty():
     {d, u} = pq.top(), pq.pop()
     if d > dist[u] continue
     For each neighbor edge [v, weight] in adj[u]:
         if dist[u] + weight < dist[v]:
             dist[v] = dist[u] + weight
             pq.push({dist[v], v})
5. Return dist.
*/

class Solution {
public:
    vector<int> dijkstra(vector<vector<pair<int, int>>>& adj, int src) {
        int V = adj.size();
        vector<int> dist(V, INT_MAX);

        // Min-heap: {distance, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (const auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;

                if (dist[u] + weight < dist[v]) {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }

        return dist;
    }
};
