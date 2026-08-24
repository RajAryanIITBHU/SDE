// Link: https://leetcode.com/problems/possible-bipartition/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS 2-Coloring on Dislike Graph)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Build adjacency list for dislikes.
2. Initialize color array of size n+1 with 0.
3. For i from 1 to n:
     if color[i] == 0:
         color[i] = 1
         queue<int> q, push i
         While !q.empty():
             u = q.front(), q.pop()
             For each v in adj[u]:
                 if color[v] == 0:
                     color[v] = -color[u]
                     q.push(v)
                 else if color[v] == color[u]:
                     return false
4. Return true.
*/

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n + 1);

        for (auto& d : dislikes) {
            adj[d[0]].push_back(d[1]);
            adj[d[1]].push_back(d[0]);
        }

        vector<int> color(n + 1, 0); // 0: uncolored, 1: group 1, -1: group 2

        for (int i = 1; i <= n; i++) {
            if (color[i] != 0) continue;

            color[i] = 1;
            queue<int> q;
            q.push(i);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == 0) {
                        color[v] = -color[u];
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
