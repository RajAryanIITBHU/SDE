// Link: https://leetcode.com/problems/find-eventual-safe-states/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Reverse Graph + Kahn's Algorithm)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Terminal nodes have outDegree == 0.
2. Reverse all edges: reverseAdj[v].push_back(u), inDegree[u] = graph[u].size().
3. Push all nodes with inDegree == 0 into queue q.
4. While !q.empty():
     node = q.front(), q.pop()
     ans.push_back(node)
     For each neighbor in reverseAdj[node]:
         inDegree[neighbor]--
         if inDegree[neighbor] == 0 -> q.push(neighbor)
5. Sort ans and return.
*/

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> reverseAdj(n);
        vector<int> inDegree(n, 0);

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                reverseAdj[v].push_back(u); // Reverse direction of edge
            }
            inDegree[u] = graph[u].size(); // Original out-degree becomes in-degree
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> safeNodes;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            safeNodes.push_back(node);

            for (int neighbor : reverseAdj[node]) {
                inDegree[neighbor]--;
                if (inDegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        sort(safeNodes.begin(), safeNodes.end());
        return safeNodes;
    }
};
