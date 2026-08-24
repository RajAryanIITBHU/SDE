// Link: https://leetcode.com/problems/minimum-height-trees/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Leaf Trimming BFS)
// ==========================================
// Time Complexity  : O(V + E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. If n == 1 return {0}.
2. Build adjacency list adj and compute degree for all nodes.
3. Push all leaf nodes (degree == 1) into queue q.
4. remainingNodes = n.
5. While remainingNodes > 2:
     leafCount = q.size()
     remainingNodes -= leafCount
     For i from 0 to leafCount - 1:
         leaf = q.front(), q.pop()
         For each neighbor in adj[leaf]:
             degree[neighbor]--
             if degree[neighbor] == 1 -> q.push(neighbor)
6. Collect remaining nodes in q and return.
*/

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                q.push(i);
            }
        }

        int remainingNodes = n;

        // Trim leaves until at most 2 centroid nodes remain
        while (remainingNodes > 2) {
            int leafCount = q.size();
            remainingNodes -= leafCount;

            for (int i = 0; i < leafCount; i++) {
                int leaf = q.front();
                q.pop();

                for (int neighbor : adj[leaf]) {
                    degree[neighbor]--;
                    if (degree[neighbor] == 1) {
                        q.push(neighbor);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
