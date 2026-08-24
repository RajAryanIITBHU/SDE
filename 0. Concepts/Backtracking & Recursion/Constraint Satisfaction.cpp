/*
 * ============================================================================
 * Concept: Constraint Satisfaction (N-Queens & Sudoku)
 * Subtopic: Backtracking & Recursion
 * ============================================================================
 * 
 * 1. WHAT DOES THE ALGORITHM / CONCEPT DO?
 * Solves highly constrained combinatorial puzzles.
- N-Queens (LC 51): Track column, positive diagonal `(r+c)`, and negative diagonal `(r-c)` sets.
- Sudoku Solver (LC 37): Try digits 1..9, check row, col, and 3x3 box validity.
 * 
 * 2. TIME & SPACE COMPLEXITY:
 * - Time Complexity: O(N!) for N-Queens, O(9^(N^2)) for Sudoku.
 * - Space Complexity: O(N) stack space.
 * 
 * 3. HOW TO APPLY (RECOGNITION SIGNALS):
 * - N-Queens I & II (LC 51, 52).
- Sudoku Solver (LC 37).
 * 
 * 4. KEY VARIATIONS & EDGE CASES TO KNOW:
 * 1. N-Queens Solver.
 */

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

void solveNQueensHelper(int r, int n, unordered_set<int>& cols, unordered_set<int>& diag1,
                        unordered_set<int>& diag2, vector<string>& board, vector<vector<string>>& result) {
    if (r == n) {
        result.push_back(board);
        return;
    }
    for (int c = 0; c < n; ++c) {
        if (cols.count(c) || diag1.count(r + c) || diag2.count(r - c)) continue;
        board[r][c] = 'Q';
        cols.insert(c); diag1.insert(r + c); diag2.insert(r - c);

        solveNQueensHelper(r + 1, n, cols, diag1, diag2, board, result);

        board[r][c] = '.';
        cols.erase(c); diag1.erase(r + c); diag2.erase(r - c); // Backtrack
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    unordered_set<int> cols, diag1, diag2;
    solveNQueensHelper(0, n, cols, diag1, diag2, board, result);
    return result;
}

int main() {
    auto res = solveNQueens(4);
    cout << "N-Queens (4x4) Solutions: " << res.size() << "\n"; // 2
    return 0;
}
