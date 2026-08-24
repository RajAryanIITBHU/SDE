// Link: https://leetcode.com/problems/n-queens-ii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with 3 Lookup Arrays: Cols, Diag1, Diag2)
// ==========================================
// Time Complexity  : O(n!)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Maintain cols, diag1 (r - c + n - 1), diag2 (r + c) boolean arrays.
2. Helper backtrack(r, n, solutionsCount):
     if r == n:
         solutionsCount++
         return
     For c from 0 to n-1:
         d1 = r - c + n - 1
         d2 = r + c
         if cols[c] || diag1[d1] || diag2[d2] continue
         cols[c] = diag1[d1] = diag2[d2] = true
         backtrack(r + 1, n, solutionsCount)
         cols[c] = diag1[d1] = diag2[d2] = false // Backtrack
3. Return solutionsCount.
*/

class Solution {
private:
    void backtrack(int r, int n, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int& count) {
        if (r == n) {
            count++;
            return;
        }

        for (int c = 0; c < n; c++) {
            int d1 = r - c + n - 1;
            int d2 = r + c;

            if (cols[c] || diag1[d1] || diag2[d2]) continue;

            cols[c] = diag1[d1] = diag2[d2] = true;
            backtrack(r + 1, n, cols, diag1, diag2, count);
            cols[c] = diag1[d1] = diag2[d2] = false; // Backtrack
        }
    }

public:
    int totalNQueens(int n) {
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false);
        vector<bool> diag2(2 * n - 1, false);
        int count = 0;

        backtrack(0, n, cols, diag1, diag2, count);
        return count;
    }
};
