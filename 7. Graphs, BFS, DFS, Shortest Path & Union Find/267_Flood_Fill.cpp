// Link: https://leetcode.com/problems/flood-fill/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Grid DFS Color Replacement)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m) recursion stack
/*
PSEUDOCODE:
1. origColor = image[sr][sc].
2. If origColor == color return image.
3. Helper dfs(r, c):
     if r < 0 || r >= n || c < 0 || c >= m || image[r][c] != origColor return
     image[r][c] = color
     For each (dr, dc) in dirs:
         dfs(r + dr, c + dc)
4. dfs(sr, sc).
5. Return image.
*/

class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<int>>& image, int r, int c, int origColor, int newColor, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || image[r][c] != origColor) {
            return;
        }

        image[r][c] = newColor;

        for (auto& dir : dirs) {
            dfs(image, r + dir.first, c + dir.second, origColor, newColor, n, m);
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origColor = image[sr][sc];
        if (origColor == color) return image;

        int n = image.size();
        int m = image[0].size();

        dfs(image, sr, sc, origColor, color, n, m);

        return image;
    }
};
