// Link: https://leetcode.com/problems/network-delay-time/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Dijkstra's Shortest Path Algorithm)
// ==========================================
// Time Complexity  : O(E log V)
// Space Complexity : O(V + E)
/*
PSEUDOCODE:
1. Build adjacency list: adj[u] = list of {v, weight}.
2. dist array of size n+1 initialized to INT_MAX, dist[k] = 0.
3. Min-heap pq storing {dist, node}, push {0, k}.
4. While !pq.empty():
     {d, u} = pq.top(), pq.pop()
     if d > dist[u] continue
     For each {v, w} in adj[u]:
         if dist[u] + w < dist[v]:
             dist[v] = dist[u] + w
             pq.push({dist[v], v})
5. maxTime = max(dist[1..n]).
6. Return maxTime == INT_MAX ? -1 : maxTime.
*/

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for (auto& t : times) {
            adj[t[0]].push_back({t[1], t[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            auto [d, u] = pq.top();
            pq.pop();

            if (d > dist[u]) continue;

            for (auto& edge : adj[u]) {
                int v = edge.first;
                int w = edge.second;

                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                    pq.push({dist[v], v});
                }
            }
        }

        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1;
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};
