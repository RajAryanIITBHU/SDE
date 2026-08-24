// Link: https://leetcode.com/problems/critical-connections-in-a-network/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Tarjan's Bridge-Finding Algorithm)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Maintain disc (discovery time) and low (lowest discovery time reachable via back-edges).
2. Helper dfs(u, parent, time):
     disc[u] = low[u] = ++time
     For each v in adj[u]:
         if v == parent continue
         if disc[v] != -1: // Back-edge
             low[u] = min(low[u], disc[v])
         else: // Tree-edge
             dfs(v, u, time)
             low[u] = min(low[u], low[v])
             if low[v] > disc[u]: // (u, v) is a bridge / critical connection!
                 bridges.push_back({u, v})
3. Return bridges.
*/

class Solution {
private:
    void dfs(int u, int parent, int& time, vector<int>& disc, vector<int>& low, vector<vector<int>>& adj, vector<vector<int>>& bridges) {
        disc[u] = low[u] = ++time;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (disc[v] != -1) {
                // Back-edge
                low[u] = min(low[u], disc[v]);
            } else {
                // Forward tree-edge
                dfs(v, u, time, disc, low, adj, bridges);
                low[u] = min(low[u], low[v]);

                // Bridge condition
                if (low[v] > disc[u]) {
                    bridges.push_back({u, v});
                }
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto& conn : connections) {
            adj[conn[0]].push_back(conn[1]);
            adj[conn[1]].push_back(conn[0]);
        }

        vector<int> disc(n, -1);
        vector<int> low(n, -1);
        vector<vector<int>> bridges;
        int time = 0;

        for (int i = 0; i < n; i++) {
            if (disc[i] == -1) {
                dfs(i, -1, time, disc, low, adj, bridges);
            }
        }

        return bridges;
    }
};
