// Link: https://leetcode.com/problems/swim-in-rising-water/

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Dijkstra's Min-Max Elevation Algorithm)
// ==========================================
// Time Complexity  : O(n^2 log n)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. Initialize time matrix of size n x n with INT_MAX, time[0][0] = grid[0][0].
2. Min-heap pq storing {time, {r, c}}, push {grid[0][0], {0, 0}}.
3. While !pq.empty():
     {t, {r, c}} = pq.top(), pq.pop()
     if r == n - 1 && c == n - 1 return t
     if t > time[r][c] continue
     For each (dr, dc) in dirs:
         nr = r + dr, nc = c + dc
         if nr >= 0 && nr < n && nc >= 0 && nc < n:
             nextTime = max(t, grid[nr][nc])
             if nextTime < time[nr][nc]:
                 time[nr][nc] = nextTime
                 pq.push({nextTime, {nr, nc}})
4. Return 0.
*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> minTime(n, vector<int>(n, INT_MAX));
        // min-heap: {time, {r, c}}
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> pq;

        minTime[0][0] = grid[0][0];
        pq.push({grid[0][0], {0, 0}});

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!pq.empty()) {
            auto topElem = pq.top();
            pq.pop();

            int t = topElem.first;
            int r = topElem.second.first;
            int c = topElem.second.second;

            if (r == n - 1 && c == n - 1) {
                return t;
            }

            if (t > minTime[r][c]) continue;

            for (auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
                    int nextTime = max(t, grid[nr][nc]);

                    if (nextTime < minTime[nr][nc]) {
                        minTime[nr][nc] = nextTime;
                        pq.push({nextTime, {nr, nc}});
                    }
                }
            }
        }

        return 0;
    }
};
