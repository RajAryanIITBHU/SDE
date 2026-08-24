// Link: https://www.geeksforgeeks.org/problems/topological-sort/1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Kahn's Algorithm / BFS In-Degree)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. Compute inDegree for each vertex.
2. Queue q, push all vertices with inDegree == 0.
3. vector<int> topoOrder.
4. While !q.empty():
     curr = q.front(), q.pop()
     topoOrder.push_back(curr)
     For neighbor in adj[curr]:
         inDegree[neighbor]--
         if inDegree[neighbor] == 0:
             q.push(neighbor)
5. Return topoOrder.
*/

class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& adj) {
        vector<int> inDegree(V, 0);

        for (int u = 0; u < V; u++) {
            for (int v : adj[u]) {
                inDegree[v]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topoOrder;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            topoOrder.push_back(curr);

            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return topoOrder;
    }
};
