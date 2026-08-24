/*
 * ============================================================================
 * Concept: In-place Matrix Transformations & State Compression
 * Subtopic: Microsoft High-Frequency Real OA & GFG Interview Classics
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Encodes 2D state changes in-place using bitwise operations or integer markers to achieve O(1) space.
Example: Game of Life (LC 289):
- State 0: dead -> dead
- State 1: live -> live
- State 2: live -> dead
- State 3: dead -> live
Bitwise trick: `cell & 1` for current state, `cell >> 1` for next state.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(R * C) time complexity.
 * - Space Complexity: O(1) auxiliary space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Game of Life (LC 289).
- Set Matrix Zeroes (LC 73).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Game of Life (LC 289).
 */

#include <iostream>
#include <vector>

using namespace std;

void gameOfLife(vector<vector<int>>& board) {
    int rows = board.size(), cols = board[0].size();
    vector<pair<int, int>> dirs = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{1,-1},{-1,1},{-1,-1}};

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            int liveNeighbors = 0;
            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && (board[nr][nc] & 1)) {
                    liveNeighbors++;
                }
            }
            if ((board[r][c] & 1) && (liveNeighbors == 2 || liveNeighbors == 3)) {
                board[r][c] |= 2; // Next state live (0b10)
            } else if (!(board[r][c] & 1) && liveNeighbors == 3) {
                board[r][c] |= 2; // Next state live
            }
        }
    }

    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < cols; ++c) {
            board[r][c] >>= 1; // Update to next state
        }
    }
}

int main() {
    vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
    gameOfLife(board);
    cout << "Next Gen Top-Left: " << board[0][0] << "\n";
    return 0;
}
