// Link: https://leetcode.com/problems/shortest-cycle-in-a-graph/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS from Each Node to Find Shortest Cycle)
// ==========================================
// Time Complexity  : O(V * (V + E))
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. minCycle = INT_MAX.
2. For src from 0 to n-1:
     dist array initialized to -1, parent array initialized to -1.
     dist[src] = 0, queue<int> q, push src.
     While !q.empty():
         u = q.front(), q.pop()
         For each v in adj[u]:
             if dist[v] == -1:
                 dist[v] = dist[u] + 1
                 parent[v] = u
                 q.push(v)
             else if parent[u] != v: // Cycle detected!
                 minCycle = min(minCycle, dist[u] + dist[v] + 1)
3. Return minCycle == INT_MAX ? -1 : minCycle.
*/

class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int minCycle = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> dist(n, -1);
            vector<int> parent(n, -1);
            queue<int> q;

            dist[i] = 0;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        parent[v] = u;
                        q.push(v);
                    } else if (parent[u] != v) {
                        // Found an alternate path connecting to visited vertex
                        minCycle = min(minCycle, dist[u] + dist[v] + 1);
                    }
                }
            }
        }

        return (minCycle == INT_MAX) ? -1 : minCycle;
    }
};
