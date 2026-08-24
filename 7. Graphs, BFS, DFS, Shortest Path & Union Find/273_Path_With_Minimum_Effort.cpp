// Link: https://leetcode.com/problems/path-with-minimum-effort/

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Dijkstra's Algorithm on Grid)
// ==========================================
// Time Complexity  : O(n * m * log(n * m))
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
1. Initialize effort matrix of size n x m with INT_MAX, effort[0][0] = 0.
2. Min-heap pq storing {effort, {r, c}}, push {0, {0, 0}}.
3. While !pq.empty():
     {d, {r, c}} = pq.top(), pq.pop()
     if r == n - 1 && c == m - 1 return d
     if d > effort[r][c] continue
     For each (dr, dc) in dirs:
         nr = r + dr, nc = c + dc
         if nr >= 0 && nr < n && nc >= 0 && nc < m:
             newEffort = max(d, abs(heights[r][c] - heights[nr][nc]))
             if newEffort < effort[nr][nc]:
                 effort[nr][nc] = newEffort
                 pq.push({newEffort, {nr, nc}})
4. Return 0.
*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> effort(n, vector<int>(m, INT_MAX));
        // min-heap: {effort, {r, c}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        effort[0][0] = 0;
        pq.push({0, {0, 0}});

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto topElem = pq.top();
            pq.pop();

            int d = topElem.first;
            int r = topElem.second.first;
            int c = topElem.second.second;

            if (r == n - 1 && c == m - 1) {
                return d;
            }

            if (d > effort[r][c]) continue;

            for (auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m) {
                    int nextEffort = max(d, abs(heights[r][c] - heights[nr][nc]));

                    if (nextEffort < effort[nr][nc]) {
                        effort[nr][nc] = nextEffort;
                        pq.push({nextEffort, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};
