// Link: https://leetcode.com/problems/pacific-atlantic-water-flow/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Reverse DFS from Ocean Boundaries)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
1. Maintain pacificVis and atlanticVis boolean matrices.
2. Helper dfs(r, c, vis, prevHeight):
     if r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || heights[r][c] < prevHeight return
     vis[r][c] = true
     For each (dr, dc) in dirs:
         dfs(r + dr, c + dc, vis, heights[r][c])
3. Run DFS for all cells bordering Pacific Ocean.
4. Run DFS for all cells bordering Atlantic Ocean.
5. Cells where pacificVis[r][c] && atlanticVis[r][c] are added to ans.
6. Return ans.
*/

class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& heights, int r, int c, vector<vector<bool>>& vis, int prevHeight, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || vis[r][c] || heights[r][c] < prevHeight) {
            return;
        }

        vis[r][c] = true;

        for (auto& dir : dirs) {
            dfs(heights, r + dir.first, c + dir.second, vis, heights[r][c], n, m);
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));

        // Pacific ocean boundaries (top row, left col)
        for (int i = 0; i < n; i++) dfs(heights, i, 0, pacific, heights[i][0], n, m);
        for (int j = 0; j < m; j++) dfs(heights, 0, j, pacific, heights[0][j], n, m);

        // Atlantic ocean boundaries (bottom row, right col)
        for (int i = 0; i < n; i++) dfs(heights, i, m - 1, atlantic, heights[i][m - 1], n, m);
        for (int j = 0; j < m; j++) dfs(heights, n - 1, j, atlantic, heights[n - 1][j], n, m);

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
