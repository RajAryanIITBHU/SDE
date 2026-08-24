// Link: https://leetcode.com/problems/valid-sudoku/

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Three Separate Validations)
// ==========================================
// Time Complexity  : O(1) (fixed 9x9 board)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Validate all 9 rows using a set for each row.
2. Validate all 9 columns using a set for each column.
3. Validate all 9 3x3 sub-boxes using a set for each box.
4. If no duplicates are found, return true.
*/

class SolutionBetter {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Validate rows
        for (int i = 0; i < 9; i++) {
            unordered_set<char> st;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (st.count(board[i][j])) return false;
                    st.insert(board[i][j]);
                }
            }
        }

        // Validate columns
        for (int j = 0; j < 9; j++) {
            unordered_set<char> st;
            for (int i = 0; i < 9; i++) {
                if (board[i][j] != '.') {
                    if (st.count(board[i][j])) return false;
                    st.insert(board[i][j]);
                }
            }
        }

        // Validate 3x3 boxes
        for (int block = 0; block < 9; block++) {
            unordered_set<char> st;
            int startRow = (block / 3) * 3;
            int startCol = (block % 3) * 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    char c = board[startRow + i][startCol + j];
                    if (c != '.') {
                        if (st.count(c)) return false;
                        st.insert(c);
                    }
                }
            }
        }

        return true;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Single Pass 2D Marker Arrays)
// ==========================================
// Time Complexity  : O(1) (81 cells total)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Create 2D marker boolean arrays:
     rowUsed[9][9], colUsed[9][9], boxUsed[9][9].
2. For each cell (i, j) in 9x9 board:
     if board[i][j] != '.':
         digit = board[i][j] - '1'
         boxIdx = (i / 3) * 3 + (j / 3)
         if rowUsed[i][digit] || colUsed[j][digit] || boxUsed[boxIdx][digit]:
             return false
         mark rowUsed[i][digit] = colUsed[j][digit] = boxUsed[boxIdx][digit] = 1
3. Return true.
*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<int>> rowUsed(9, vector<int>(9, 0));
        vector<vector<int>> colUsed(9, vector<int>(9, 0));
        vector<vector<int>> boxUsed(9, vector<int>(9, 0));

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    int digit = board[i][j] - '1';
                    int boxIdx = (i / 3) * 3 + (j / 3);

                    // If digit already used in row, col, or 3x3 box
                    if (rowUsed[i][digit] || colUsed[j][digit] || boxUsed[boxIdx][digit]) {
                        return false;
                    }

                    rowUsed[i][digit] = 1;
                    colUsed[j][digit] = 1;
                    boxUsed[boxIdx][digit] = 1;
                }
            }
        }

        return true;
    }
};
