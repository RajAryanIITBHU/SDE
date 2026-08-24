// Link: https://leetcode.com/problems/path-with-maximum-probability/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Max-Heap Dijkstra on Probabilities)
// ==========================================
// Time Complexity  : O(E log V)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Build adjacency list: adj[u] = list of {v, succProb}.
2. prob array of size n initialized to 0.0, prob[start] = 1.0.
3. Max-heap pq storing {prob, node}, push {1.0, start}.
4. While !pq.empty():
     {p, u} = pq.top(), pq.pop()
     if u == end_node return p
     if p < prob[u] continue
     For each {v, edgeProb} in adj[u]:
         if prob[u] * edgeProb > prob[v]:
             prob[v] = prob[u] * edgeProb
             pq.push({prob[v], v})
5. Return 0.0.
*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adj(n);

        for (int i = 0; i < (int)edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            adj[u].push_back({v, p});
            adj[v].push_back({u, p});
        }

        vector<double> maxProb(n, 0.0);
        // Max-heap: {probability, node}
        priority_queue<pair<double, int>> pq;

        maxProb[start_node] = 1.0;
        pq.push({1.0, start_node});

        while (!pq.empty()) {
            auto [p, u] = pq.top();
            pq.pop();

            if (u == end_node) {
                return p;
            }

            if (p < maxProb[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                double edgeProb = edge.second;

                if (maxProb[u] * edgeProb > maxProb[v]) {
                    maxProb[v] = maxProb[u] * edgeProb;
                    pq.push({maxProb[v], v});
                }
            }
        }

        return 0.0;
    }
};
