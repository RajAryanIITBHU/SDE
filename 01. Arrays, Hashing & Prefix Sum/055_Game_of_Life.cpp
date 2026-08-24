// Link: https://leetcode.com/problems/game-of-life/

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Copy Matrix)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
1. Make a copy of board called arr.
2. For each cell (i, j):
     Count live neighbors in arr.
     Apply Conway's rules and update board[i][j].
*/

class SolutionBetter {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<int>> arr = board;

        vector<vector<int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int liveNeighbors = 0;

                for (auto& dir : dirs) {
                    int r = i + dir[0];
                    int c = j + dir[1];
                    if (r >= 0 && r < n && c >= 0 && c < m && arr[r][c] == 1) {
                        liveNeighbors++;
                    }
                }

                if (arr[i][j] == 1) {
                    if (liveNeighbors < 2 || liveNeighbors > 3) board[i][j] = 0;
                } else {
                    if (liveNeighbors == 3) board[i][j] = 1;
                }
            }
        }
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (In-place State Encoding)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
State Transition Encoding:
  0 -> 0 : 0
  1 -> 1 : 1
  1 -> 0 : 2 (was alive, now dead)
  0 -> 1 : 3 (was dead, now alive)

1. For each cell (i, j):
     Count neighbors that were originally alive (state 1 or 2).
     If cell == 1 and (neighbors < 2 || neighbors > 3) -> board[i][j] = 2
     If cell == 0 and neighbors == 3 -> board[i][j] = 3
2. Second pass to decode final states:
     board[i][j] %= 2 (or 1 if state 1 or 3, else 0)
*/

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<vector<int>> dirs = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};

        // Step 1: Transition and encode states
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int liveNeighbors = 0;

                for (auto& dir : dirs) {
                    int r = i + dir[0];
                    int c = j + dir[1];
                    // Original live states are 1 and 2
                    if (r >= 0 && r < n && c >= 0 && c < m && (board[r][c] == 1 || board[r][c] == 2)) {
                        liveNeighbors++;
                    }
                }

                // Rule 1 & 3: Live cell dies
                if (board[i][j] == 1 && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[i][j] = 2; // 1 -> 0
                }
                // Rule 4: Dead cell becomes alive
                else if (board[i][j] == 0 && liveNeighbors == 3) {
                    board[i][j] = 3; // 0 -> 1
                }
            }
        }

        // Step 2: Final decoding
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                board[i][j] %= 2; // States 1 and 3 become 1, states 0 and 2 become 0
            }
        }
    }
};
