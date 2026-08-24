// Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS with Bitmask State)
// ==========================================
// Time Complexity  : O(n * 2^n)
// Space Complexity : O(n * 2^n)
/*
PSEUDOCODE:
1. Target mask = (1 << n) - 1.
2. Initialize queue<pair<int, int>> q storing {node, visitedMask}.
3. vis[node][mask] boolean table initialized to false.
4. Push all nodes with their single-bit masks: q.push({i, 1 << i}), vis[i][1 << i] = true.
5. steps = 0.
6. While !q.empty():
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         {u, mask} = q.front(), q.pop()
         if mask == targetMask return steps
         For each v in graph[u]:
             nextMask = mask | (1 << v)
             if !vis[v][nextMask]:
                 vis[v][nextMask] = true
                 q.push({v, nextMask})
     steps++
7. Return 0.
*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        if (n == 1) return 0;

        int targetMask = (1 << n) - 1;
        vector<vector<bool>> vis(n, vector<bool>(1 << n, false));
        queue<pair<int, int>> q; // {node, mask}

        // Start BFS simultaneously from all nodes
        for (int i = 0; i < n; i++) {
            q.push({i, 1 << i});
            vis[i][1 << i] = true;
        }

        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [u, mask] = q.front();
                q.pop();

                if (mask == targetMask) {
                    return steps;
                }

                for (int v : graph[u]) {
                    int nextMask = mask | (1 << v);

                    if (!vis[v][nextMask]) {
                        vis[v][nextMask] = true;
                        q.push({v, nextMask});
                    }
                }
            }

            steps++;
        }

        return 0;
    }
};
