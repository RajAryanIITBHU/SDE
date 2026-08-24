// Link: https://leetcode.com/problems/n-queens/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with Board String Generation)
// ==========================================
// Time Complexity  : O(n!)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize empty n x n board of '.' characters.
2. Maintain cols, diag1 (r - c + n - 1), diag2 (r + c) boolean lookup arrays.
3. Helper backtrack(r, n, board, cols, diag1, diag2, ans):
     if r == n:
         ans.push_back(board)
         return
     For c from 0 to n-1:
         d1 = r - c + n - 1
         d2 = r + c
         if cols[c] || diag1[d1] || diag2[d2] continue
         board[r][c] = 'Q'
         cols[c] = diag1[d1] = diag2[d2] = true
         backtrack(r + 1, n, board, cols, diag1, diag2, ans)
         board[r][c] = '.'
         cols[c] = diag1[d1] = diag2[d2] = false // Backtrack
4. backtrack(0, n, board, cols, diag1, diag2, ans).
5. Return ans.
*/

class Solution {
private:
    void backtrack(int r, int n, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, vector<vector<string>>& ans) {
        if (r == n) {
            ans.push_back(board);
            return;
        }

        for (int c = 0; c < n; c++) {
            int d1 = r - c + n - 1;
            int d2 = r + c;

            if (cols[c] || diag1[d1] || diag2[d2]) continue;

            board[r][c] = 'Q';
            cols[c] = diag1[d1] = diag2[d2] = true;

            backtrack(r + 1, n, board, cols, diag1, diag2, ans);

            board[r][c] = '.';
            cols[c] = diag1[d1] = diag2[d2] = false; // Backtrack
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        vector<vector<string>> ans;

        backtrack(0, n, board, cols, diag1, diag2, ans);
        return ans;
    }
};
