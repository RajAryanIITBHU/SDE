// Link: https://leetcode.com/problems/surrounded-regions/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Boundary Connected DFS Traversal)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m) recursion stack
/*
PSEUDOCODE:
1. Traverse all 4 borders: if board[r][c] == 'O', run DFS and convert connected 'O's to '#'.
2. Pass 2 over entire board:
     if board[r][c] == 'O' -> board[r][c] = 'X' (captured surrounded region)
     if board[r][c] == '#' -> board[r][c] = 'O' (restore boundary-connected cell)
*/

class Solution {
private:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    void dfs(vector<vector<char>>& board, int r, int c, int n, int m) {
        if (r < 0 || r >= n || c < 0 || c >= m || board[r][c] != 'O') {
            return;
        }

        board[r][c] = '#'; // Temporarily mark boundary-connected 'O'

        for (auto& dir : dirs) {
            dfs(board, r + dir.first, c + dir.second, n, m);
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // 1. Run DFS from boundary 'O's
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0, n, m);
            if (board[i][m - 1] == 'O') dfs(board, i, m - 1, n, m);
        }
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j, n, m);
            if (board[n - 1][j] == 'O') dfs(board, n - 1, j, n, m);
        }

        // 2. Flip surrounded 'O' -> 'X' and restore '#' -> 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == '#') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
