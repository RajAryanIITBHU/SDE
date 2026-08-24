/*
 * ============================================================================
 * Concept: Grid Backtracking & Word Search
 * Subtopic: Backtracking & Recursion
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Explores paths in a 2D matrix matching a string pattern.
Mark visited cells temporarily `grid[r][c] = '#'`, recursively explore 4 directions, and restore `grid[r][c] = original_char` on backtrack.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N * M * 4^L) where L is word length.
 * - Space Complexity: O(L) recursion stack space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - Word Search I (LC 79).
- Rat in a Maze / Grid Path Finding.
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. Word Search I in 2D Matrix (LC 79).
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfsWord(vector<vector<char>>& board, int r, int c, string& word, int idx) {
    if (idx == (int)word.length()) return true;
    int rows = board.size(), cols = board[0].size();
    if (r < 0 || r >= rows || c < 0 || c >= cols || board[r][c] != word[idx]) return false;

    char temp = board[r][c];
    board[r][c] = '#'; // Mark visited

    bool found = dfsWord(board, r + 1, c, word, idx + 1) ||
                 dfsWord(board, r - 1, c, word, idx + 1) ||
                 dfsWord(board, r, c + 1, word, idx + 1) ||
                 dfsWord(board, r, c - 1, word, idx + 1);

    board[r][c] = temp; // Backtrack
    return found;
}

bool exist(vector<vector<char>>& board, string word) {
    for (int r = 0; r < (int)board.size(); ++r) {
        for (int c = 0; c < (int)board[0].size(); ++c) {
            if (dfsWord(board, r, c, word, 0)) return true;
        }
    }
    return false;
}

int main() {
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    cout << "ABCCED Exists: " << (exist(board, "ABCCED") ? "Yes" : "No") << "\n";
    return 0;
}
