// Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Floyd-Warshall All-Pairs Shortest Path)
// ==========================================
// Time Complexity  : O(n^3)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. Initialize dist matrix n x n with INF (1e9), dist[i][i] = 0.
2. For each edge (u, v, w): dist[u][v] = w, dist[v][u] = w.
3. Floyd-Warshall:
     For k from 0 to n-1:
         For i from 0 to n-1:
             For j from 0 to n-1:
                 dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])
4. minReachable = INF, bestCity = -1.
5. For i from 0 to n-1:
     reachable = count of j where dist[i][j] <= distanceThreshold
     if reachable <= minReachable:
         minReachable = reachable
         bestCity = i
6. Return bestCity.
*/

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        const int INF = 1e9;
        vector<vector<int>> dist(n, vector<int>(n, INF));

        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = w;
            dist[v][u] = w;
        }

        // Floyd-Warshall Algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int minReachable = INF;
        int bestCity = -1;

        for (int i = 0; i < n; i++) {
            int reachable = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    reachable++;
                }
            }

            // Tie-breaker: choose greatest city index
            if (reachable <= minReachable) {
                minReachable = reachable;
                bestCity = i;
            }
        }

        return bestCity;
    }
};
