// Link: https://leetcode.com/problems/min-cost-to-connect-all-points/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Prim's Minimum Spanning Tree Algorithm)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. minDist array of size n initialized to INT_MAX, inMST boolean array of size n.
2. minDist[0] = 0, totalCost = 0.
3. For i from 0 to n-1:
     Find unvisited node u with minimum minDist:
     inMST[u] = true
     totalCost += minDist[u]
     For v from 0 to n-1:
         if !inMST[v]:
             dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1])
             minDist[v] = min(minDist[v], dist)
4. Return totalCost.
*/

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> minDist(n, INT_MAX);
        vector<bool> inMST(n, false);

        minDist[0] = 0;
        int totalCost = 0;

        for (int i = 0; i < n; i++) {
            int u = -1;

            // Pick vertex with minimum distance not yet included in MST
            for (int j = 0; j < n; j++) {
                if (!inMST[j] && (u == -1 || minDist[j] < minDist[u])) {
                    u = j;
                }
            }

            inMST[u] = true;
            totalCost += minDist[u];

            // Update distance to all unvisited neighbors
            for (int v = 0; v < n; v++) {
                if (!inMST[v]) {
                    int dist = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minDist[v] = min(minDist[v], dist);
                }
            }
        }

        return totalCost;
    }
};
