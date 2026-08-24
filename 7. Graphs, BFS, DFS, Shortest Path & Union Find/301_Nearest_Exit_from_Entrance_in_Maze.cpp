// Link: https://leetcode.com/problems/nearest-exit-from-entrance-in-maze/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (BFS Shortest Path in Maze)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
1. Initialize queue<pair<int, int>> q, push entrance, maze[r][c] = '+' (mark visited), steps = 0.
2. While !q.empty():
     levelSize = q.size()
     For i from 0 to levelSize - 1:
         {r, c} = q.front(), q.pop()
         if (r != entrance[0] || c != entrance[1]) && (r == 0 || r == n - 1 || c == 0 || c == m - 1):
             return steps // Boundary exit found!
         For each (dr, dc) in dirs:
             nr = r + dr, nc = c + dc
             if nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == '.':
                 maze[nr][nc] = '+'
                 q.push({nr, nc})
     steps++
3. Return -1.
*/

class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>> q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+'; // Mark visited

        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [r, c] = q.front();
                q.pop();

                // Exit condition: on the border and not the starting entrance
                if ((r != entrance[0] || c != entrance[1]) && (r == 0 || r == n - 1 || c == 0 || c == m - 1)) {
                    return steps;
                }

                for (auto& dir : dirs) {
                    int nr = r + dir.first;
                    int nc = c + dir.second;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m && maze[nr][nc] == '.') {
                        maze[nr][nc] = '+';
                        q.push({nr, nc});
                    }
                }
            }

            steps++;
        }

        return -1;
    }
};
