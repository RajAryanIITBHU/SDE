// Link: https://leetcode.com/problems/detonate-the-maximum-bombs/

#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Directed Graph Construction + DFS Reachability)
// ==========================================
// Time Complexity  : O(n^3)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. Build directed graph adj:
     Add edge i -> j if Euclidean distance (x_i - x_j)^2 + (y_i - y_j)^2 <= r_i^2.
2. Helper dfs(u, visited):
     visited[u] = true
     count = 1
     For each v in adj[u]:
         if !visited[v]:
             count += dfs(v, visited)
     return count
3. maxBombs = 0.
4. For i from 0 to n-1:
     vector<bool> visited(n, false)
     maxBombs = max(maxBombs, dfs(i, visited))
5. Return maxBombs.
*/

class Solution {
private:
    int dfs(int u, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[u] = true;
        int count = 1;

        for (int v : adj[u]) {
            if (!vis[v]) {
                count += dfs(v, vis, adj);
            }
        }

        return count;
    }

public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> adj(n);

        // Build directed detonation graph
        for (int i = 0; i < n; i++) {
            long long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];

            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                long long x2 = bombs[j][0], y2 = bombs[j][1];

                long long distSq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                if (distSq <= r1 * r1) {
                    adj[i].push_back(j); // Detonation of i triggers j
                }
            }
        }

        int maxBombs = 0;

        for (int i = 0; i < n; i++) {
            vector<bool> vis(n, false);
            maxBombs = max(maxBombs, dfs(i, vis, adj));
        }

        return maxBombs;
    }
};
