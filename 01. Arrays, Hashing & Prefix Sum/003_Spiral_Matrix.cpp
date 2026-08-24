// Link: https://leetcode.com/problems/spiral-matrix/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. BRUTE FORCE / SIMULATION (Visited Matrix)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m) auxiliary space for visited matrix
/*
PSEUDOCODE:
1. Initialize visited matrix vis[n][m] with 0.
2. Define directions: Right (0, 1), Down (1, 0), Left (0, -1), Up (-1, 0).
3. Start at (r = 0, c = 0) with direction index dirIdx = 0.
4. For step from 0 to (n * m - 1):
     Add matrix[r][c] to ans.
     Mark vis[r][c] = 1.
     Calculate next position: nr = r + dirs[dirIdx][0], nc = c + dirs[dirIdx][1].
     If (nr, nc) is within bounds and not visited:
         r = nr, c = nc
     Else:
         Change direction: dirIdx = (dirIdx + 1) % 4
         r = r + dirs[dirIdx][0], c = c + dirs[dirIdx][1]
5. Return ans.
*/

class SolutionBruteForce {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> vis(n, vector<int>(m, 0));
        vector<int> ans;

        // Directions: Right, Down, Left, Up
        vector<vector<int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dirIdx = 0;

        int r = 0;
        int c = 0;

        for (int step = 0; step < n * m; step++) {
            ans.push_back(matrix[r][c]);
            vis[r][c] = 1;

            int nr = r + dirs[dirIdx][0];
            int nc = c + dirs[dirIdx][1];

            // If next cell is valid and unvisited, move there
            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0) {
                r = nr;
                c = nc;
            } else {
                // Turn clockwise
                dirIdx = (dirIdx + 1) % 4;
                r = r + dirs[dirIdx][0];
                c = c + dirs[dirIdx][1];
            }
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (4-Boundary Traversal)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Define 4 boundaries:
     top = 0, bottom = n - 1
     left = 0, right = m - 1
2. While (top <= bottom && left <= right):
     a. Traverse top row: from j = left to right -> ans.push_back(matrix[top][j]), then top++
     b. Traverse right col: from i = top to bottom -> ans.push_back(matrix[i][right]), then right--
     c. If top <= bottom:
          Traverse bottom row: from j = right down to left -> ans.push_back(matrix[bottom][j]), then bottom--
     d. If left <= right:
          Traverse left col: from i = bottom down to top -> ans.push_back(matrix[i][left]), then left++
3. Return ans.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> ans;

        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = m - 1;

        while (top <= bottom && left <= right) {
            // 1. Move Left to Right (along top boundary)
            for (int j = left; j <= right; j++) {
                ans.push_back(matrix[top][j]);
            }
            top++;

            // 2. Move Top to Bottom (along right boundary)
            for (int i = top; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }
            right--;

            // 3. Move Right to Left (along bottom boundary)
            if (top <= bottom) {
                for (int j = right; j >= left; j--) {
                    ans.push_back(matrix[bottom][j]);
                }
                bottom--;
            }

            // 4. Move Bottom to Top (along left boundary)
            if (left <= right) {
                for (int i = bottom; i >= top; i--) {
                    ans.push_back(matrix[i][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
