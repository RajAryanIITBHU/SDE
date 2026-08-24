// Link: https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prim's Algorithm / Min-Heap Priority Queue)
// ==========================================
// Time Complexity  : O(E log V)
// Space Complexity : O(V)
/*
PSEUDOCODE:
1. Min-heap pq storing {weight, node}.
2. vis array of size V initialized to false.
3. pq.push({0, 0}), mstSum = 0.
4. While !pq.empty():
     {wt, u} = pq.top(), pq.pop()
     if vis[u] continue
     vis[u] = true
     mstSum += wt
     For each neighbor [v, weight] in adj[u]:
         if !vis[v]:
             pq.push({weight, v})
5. Return mstSum.
*/

class Solution {
public:
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // Min-heap: {weight, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> vis(V, false);

        pq.push({0, 0});
        int mstSum = 0;

        while (!pq.empty()) {
            auto [wt, u] = pq.top();
            pq.pop();

            if (vis[u]) continue;

            vis[u] = true;
            mstSum += wt;

            for (const auto& neighbor : adj[u]) {
                int v = neighbor[0];
                int weight = neighbor[1];

                if (!vis[v]) {
                    pq.push({weight, v});
                }
            }
        }

        return mstSum;
    }
};
