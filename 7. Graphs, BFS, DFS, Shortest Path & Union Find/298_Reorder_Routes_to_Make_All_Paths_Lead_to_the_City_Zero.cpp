// Link: https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS from Node 0 with Edge Direction Weight)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Build bidirectional adjacency list:
     adj[u].push_back({v, 1}) (original forward edge requires reversal)
     adj[v].push_back({u, 0}) (virtual backward edge requires no change)
2. Run BFS starting from node 0:
     reversals = 0, vis array initialized to false.
     q.push(0), vis[0] = true
     While !q.empty():
         u = q.front(), q.pop()
         For each {v, needsReversal} in adj[u]:
             if !vis[v]:
                 vis[v] = true
                 reversals += needsReversal
                 q.push(v)
3. Return reversals.
*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adj(n); // {neighbor, needsReversal}

        for (auto& conn : connections) {
            int u = conn[0];
            int v = conn[1];
            adj[u].push_back({v, 1}); // Original edge away from 0
            adj[v].push_back({u, 0}); // Back edge towards 0
        }

        vector<bool> vis(n, false);
        queue<int> q;

        q.push(0);
        vis[0] = true;
        int reversals = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int cost = edge.second;

                if (!vis[v]) {
                    vis[v] = true;
                    reversals += cost;
                    q.push(v);
                }
            }
        }

        return reversals;
    }
};
