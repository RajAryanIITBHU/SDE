// Link: https://www.geeksforgeeks.org/problems/articulation-point-1/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Tarjan's DFS with Discovery & Low Times)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. tin[u], low[u], vis[u], timer = 1, isArticulation[u] = false.
2. DFS(u, parent):
     vis[u] = true
     tin[u] = low[u] = timer++
     children = 0
     For v in adj[u]:
         if v == parent continue
         if vis[v]:
             low[u] = min(low[u], tin[v]) // Back-edge
         else:
             DFS(v, u)
             low[u] = min(low[u], low[v])
             if low[v] >= tin[u] && parent != -1:
                 isArticulation[u] = true
             children++
     if parent == -1 && children > 1:
         isArticulation[u] = true
3. Collect all u where isArticulation[u] is true.
*/

class Solution {
private:
    int timer = 1;

    void dfs(int u, int parent, vector<int>& tin, vector<int>& low, vector<bool>& vis,
             vector<bool>& isArticulation, const vector<vector<int>>& adj) {
        vis[u] = true;
        tin[u] = low[u] = timer++;
        int children = 0;

        for (int v : adj[u]) {
            if (v == parent) continue;

            if (vis[v]) {
                low[u] = min(low[u], tin[v]);
            } else {
                dfs(v, u, tin, low, vis, isArticulation, adj);
                low[u] = min(low[u], low[v]);

                if (low[v] >= tin[u] && parent != -1) {
                    isArticulation[u] = true;
                }
                children++;
            }
        }

        if (parent == -1 && children > 1) {
            isArticulation[u] = true;
        }
    }

public:
    vector<int> articulationPoints(int V, vector<vector<int>>& adj) {
        vector<int> tin(V, 0);
        vector<int> low(V, 0);
        vector<bool> vis(V, false);
        vector<bool> isArticulation(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                dfs(i, -1, tin, low, vis, isArticulation, adj);
            }
        }

        vector<int> ans;
        for (int i = 0; i < V; i++) {
            if (isArticulation[i]) {
                ans.push_back(i);
            }
        }

        return ans.empty() ? vector<int>{-1} : ans;
    }
};
