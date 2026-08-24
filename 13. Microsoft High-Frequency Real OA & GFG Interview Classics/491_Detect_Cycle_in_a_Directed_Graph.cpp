// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1

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
3. visitedNodesCount = 0.
4. While !q.empty():
     curr = q.front(), q.pop()
     visitedNodesCount++
     For neighbor in adj[curr]:
         inDegree[neighbor]--
         if inDegree[neighbor] == 0:
             q.push(neighbor)
5. Return visitedNodesCount != V (if visited count < V, cycle exists).
*/

class Solution {
public:
    bool isCyclic(int V, vector<vector<int>> adj) {
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

        int count = 0;
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            count++;

            for (int neighbor : adj[curr]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        return count != V; // If count != V, there is a cycle
    }
};
