// Link: https://leetcode.com/problems/is-graph-bipartite/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS 2-Coloring)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. Initialize color array of size n with 0 (0: unvisited, 1: color 1, -1: color 2).
2. For i from 0 to n-1:
     if color[i] == 0:
         color[i] = 1
         queue<int> q, push i
         While !q.empty():
             u = q.front(), q.pop()
             For each v in graph[u]:
                 if color[v] == 0:
                     color[v] = -color[u]
                     q.push(v)
                 else if color[v] == color[u]:
                     return false // Same color on adjacent nodes!
3. Return true.
*/

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 0: uncolored, 1: blue, -1: red

        for (int i = 0; i < n; i++) {
            if (color[i] != 0) continue;

            color[i] = 1;
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : graph[u]) {
                    if (color[v] == 0) {
                        color[v] = -color[u]; // Color with opposite color
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false; // Same color on adjacent vertices
                    }
                }
            }
        }

        return true;
    }
};
