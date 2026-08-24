// Link: https://leetcode.com/problems/minimum-moves-to-move-a-box-to-their-target-location/

#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Nested BFS / State Space Search)
// ==========================================
// Time Complexity  : O((n * m)^2)
// Space Complexity : O((n * m)^2)
/*
PSEUDOCODE:
State: (boxR, boxC, playerR, playerC)
1. Find positions of Player 'S', Box 'B', Target 'T'.
2. Helper canPlayerReach(targetR, targetC, boxR, boxC, startR, startC):
     Runs BFS on grid to check if player can reach (targetR, targetC) without stepping on the box.
3. Queue storing {pushes, boxR, boxC, playerR, playerC}.
4. While !q.empty():
     Pop current state.
     if box == target return pushes.
     Try 4 pushing directions:
         Player must be at (boxR - dr, boxC - dc) to push box to (boxR + dr, boxC + dc).
         If player can reach that cell:
             push new state (boxR + dr, boxC + dc, boxR, boxC) with pushes + 1.
5. Return -1.
*/

class Solution {
private:
    int n, m;
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    bool canPlayerReach(vector<vector<char>>& grid, int targetR, int targetC, int boxR, int boxC, int startR, int startC) {
        if (startR == targetR && startC == targetC) return true;

        vector<vector<bool>> vis(n, vector<bool>(m, false));
        queue<pair<int, int>> q;

        q.push({startR, startC});
        vis[startR][startC] = true;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            if (r == targetR && c == targetC) return true;

            for (auto& dir : dirs) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !vis[nr][nc] && grid[nr][nc] != '#' && !(nr == boxR && nc == boxC)) {
                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }

        return false;
    }

public:
    int minPushBox(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();

        int bR = 0, bC = 0, pR = 0, pC = 0, tR = 0, tC = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 'B') { bR = i; bC = j; }
                else if (grid[i][j] == 'S') { pR = i; pC = j; }
                else if (grid[i][j] == 'T') { tR = i; tC = j; }
            }
        }

        // State: {pushes, bR, bC, pR, pC}
        queue<tuple<int, int, int, int, int>> q;
        // vis[bR][bC][dirIdx]: box at (bR, bC) pushed from direction dirIdx
        vector<vector<vector<bool>>> vis(n, vector<vector<bool>>(m, vector<bool>(4, false)));

        q.push({0, bR, bC, pR, pC});

        while (!q.empty()) {
            auto [pushes, currBR, currBC, currPR, currPC] = q.front();
            q.pop();

            if (currBR == tR && currBC == tC) {
                return pushes;
            }

            for (int d = 0; d < 4; d++) {
                int newBR = currBR + dirs[d].first;
                int newBC = currBC + dirs[d].second;

                // Player must stand opposite to pushing direction
                int pushPR = currBR - dirs[d].first;
                int pushPC = currBC - dirs[d].second;

                if (newBR >= 0 && newBR < n && newBC >= 0 && newBC < m && grid[newBR][newBC] != '#' &&
                    pushPR >= 0 && pushPR < n && pushPC >= 0 && pushPC < m && grid[pushPR][pushPC] != '#') {
                    
                    if (!vis[newBR][newBC][d]) {
                        if (canPlayerReach(grid, pushPR, pushPC, currBR, currBC, currPR, currPC)) {
                            vis[newBR][newBC][d] = true;
                            q.push({pushes + 1, newBR, newBC, currBR, currBC});
                        }
                    }
                }
            }
        }

        return -1;
    }
};
