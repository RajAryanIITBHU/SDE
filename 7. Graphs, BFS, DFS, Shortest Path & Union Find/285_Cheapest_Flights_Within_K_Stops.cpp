// Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS Queue with Stops Limit)
// ==========================================
// Time Complexity  : O(K * E)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Build adjacency list: adj[u] = list of {v, price}.
2. dist array of size n initialized to INT_MAX, dist[src] = 0.
3. Queue storing {stops, {u, currentCost}}, push {0, {src, 0}}.
4. While !q.empty():
     {stops, {u, cost}} = q.front(), q.pop()
     if stops > k continue
     For each {v, price} in adj[u]:
         if cost + price < dist[v]:
             dist[v] = cost + price
             q.push({stops + 1, {v, cost + price}})
5. Return dist[dst] == INT_MAX ? -1 : dist[dst].
*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);

        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        vector<int> dist(n, INT_MAX);
        // queue: {stops, {u, cost}}
        queue<pair<int, pair<int, int>>> q;

        dist[src] = 0;
        q.push({0, {src, 0}});

        while (!q.empty()) {
            auto item = q.front();
            q.pop();

            int stops = item.first;
            int u = item.second.first;
            int cost = item.second.second;

            if (stops > k) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int price = edge.second;

                if (cost + price < dist[v]) {
                    dist[v] = cost + price;
                    q.push({stops + 1, {v, cost + price}});
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
