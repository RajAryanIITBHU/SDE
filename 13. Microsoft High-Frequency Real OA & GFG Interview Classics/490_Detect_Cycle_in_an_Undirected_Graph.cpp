// Link: https://www.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS / DFS Cycle Detection with Parent Tracking)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. vis array of size V initialized to false.
2. Helper bfsCheck(startNode, adj, vis):
     queue storing {node, parentNode}
     q.push({startNode, -1}), vis[startNode] = true
     While !q.empty():
         {curr, parent} = q.front(), q.pop()
         For neighbor in adj[curr]:
             if !vis[neighbor]:
                 vis[neighbor] = true
                 q.push({neighbor, curr})
             else if neighbor != parent:
                 return true // Back-edge implies cycle
     return false
3. For i from 0 to V-1:
     if !vis[i] && bfsCheck(i, adj, vis) return true
4. Return false.
*/

class Solution {
private:
    bool bfsCheck(int start, vector<vector<int>>& adj, vector<bool>& vis) {
        queue<pair<int, int>> q; // {currentNode, parentNode}
        vis[start] = true;
        q.push({start, -1});

        while (!q.empty()) {
            auto [curr, parent] = q.front();
            q.pop();

            for (int neighbor : adj[curr]) {
                if (!vis[neighbor]) {
                    vis[neighbor] = true;
                    q.push({neighbor, curr});
                } else if (neighbor != parent) {
                    return true; // Cycle detected
                }
            }
        }

        return false;
    }

public:
    bool isCycle(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<bool> vis(V, false);

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (bfsCheck(i, adj, vis)) {
                    return true;
                }
            }
        }

        return false;
    }
};
