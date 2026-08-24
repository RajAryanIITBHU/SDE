// Link: https://leetcode.com/problems/sudoku-solver/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Validity Checking)
// ==========================================
// Time Complexity  : O(9^(empty_cells))
// Space Complexity : O(empty_cells) recursion stack
/*
PSEUDOCODE:
1. Helper isValid(board, r, c, val):
     For i from 0 to 8:
         if board[r][i] == val return false (row check)
         if board[i][c] == val return false (col check)
         if board[3 * (r/3) + i/3][3 * (c/3) + i%3] == val return false (3x3 box check)
     return true
2. Helper solve(board):
     For r from 0 to 8:
         For c from 0 to 8:
             if board[r][c] == '.':
                 For val from '1' to '9':
                     if isValid(board, r, c, val):
                         board[r][c] = val
                         if solve(board) return true
                         board[r][c] = '.' // Backtrack
                 return false
     return true
3. solve(board).
*/

class Solution {
private:
    bool isValid(vector<vector<char>>& board, int r, int c, char val) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] == val) return false;
            if (board[i][c] == val) return false;
            if (board[3 * (r / 3) + i / 3][3 * (c / 3) + i % 3] == val) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int r = 0; r < 9; r++) {
            for (int c = 0; c < 9; c++) {
                if (board[r][c] == '.') {
                    for (char val = '1'; val <= '9'; val++) {
                        if (isValid(board, r, c, val)) {
                            board[r][c] = val;

                            if (solve(board)) {
                                return true;
                            }

                            board[r][c] = '.'; // Backtrack
                        }
                    }
                    return false; // No valid placement for this cell
                }
            }
        }
        return true; // All cells successfully filled
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
