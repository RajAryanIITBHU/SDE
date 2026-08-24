// Link: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bellman-Ford Algorithm)
// ==========================================
// Time Complexity  : O(V * E)
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. dist array of size V initialized to 1e8. dist[src] = 0.
2. Relax all edges V - 1 times:
     For each edge [u, v, wt]:
         if dist[u] != 1e8 && dist[u] + wt < dist[v]:
             dist[v] = dist[u] + wt
3. V-th relaxation check for negative cycle:
     For each edge [u, v, wt]:
         if dist[u] != 1e8 && dist[u] + wt < dist[v]:
             return {-1} // Negative weight cycle detected
4. Return dist.
*/

class Solution {
public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        const int INF = 1e8;
        vector<int> dist(V, INF);
        dist[src] = 0;

        // Relax edges V - 1 times
        for (int i = 0; i < V - 1; i++) {
            for (const auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];

                if (dist[u] != INF && dist[u] + wt < dist[v]) {
                    dist[v] = dist[u] + wt;
                }
            }
        }

        // Check for negative-weight cycle on V-th iteration
        for (const auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            if (dist[u] != INF && dist[u] + wt < dist[v]) {
                return {-1}; // Negative cycle detected
            }
        }

        return dist;
    }
};
