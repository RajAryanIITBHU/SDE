// Link: https://leetcode.com/problems/set-matrix-zeroes/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Matrix Copy)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m) auxiliary space for matrix copy
/*
PSEUDOCODE:
1. Make a copy of matrix called arr = matrix.
2. Traverse matrix:
     If matrix[i][j] == 0:
         Set entire row i to 0 in arr
         Set entire column j to 0 in arr
3. Assign matrix = arr.
*/

class SolutionBruteForce {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> arr = matrix;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    // Set row i to 0 in arr
                    for (int c = 0; c < m; c++) {
                        arr[i][c] = 0;
                    }
                    // Set column j to 0 in arr
                    for (int r = 0; r < n; r++) {
                        arr[r][j] = 0;
                    }
                }
            }
        }

        matrix = arr;
    }
};

// ==========================================
// 2. BETTER APPROACH (Marker Arrays)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n + m) for row and column markers
/*
PSEUDOCODE:
1. Create marker arrays: row(n, 0) and col(m, 0).
2. Traverse matrix:
     If matrix[i][j] == 0 -> row[i] = 1, col[j] = 1.
3. Traverse matrix again:
     If row[i] == 1 OR col[j] == 1 -> matrix[i][j] = 0.
*/

class SolutionBetter {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> row(n, 0);
        vector<int> col(m, 0);

        // Step 1: Mark rows and columns that contain 0
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = 1;
                    col[j] = 1;
                }
            }
        }

        // Step 2: Set matrix cells to 0 based on markers
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (row[i] == 1 || col[j] == 1) {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (In-place Marker Row/Col)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(1) auxiliary space
/*
PSEUDOCODE:
1. Use 1st row and 1st column of matrix as marker arrays.
2. Track col0 = 1 for the 0th column.
3. Traverse matrix:
     If matrix[i][0] == 0 -> col0 = 0
     For j from 1 to m-1:
         If matrix[i][j] == 0:
             matrix[i][0] = 0
             matrix[0][j] = 0
4. Traverse inner submatrix from (1,1) to (n-1, m-1):
     If matrix[i][0] == 0 OR matrix[0][j] == 0 -> matrix[i][j] = 0
5. If matrix[0][0] == 0 -> set entire 1st row to 0.
6. If col0 == 0 -> set entire 1st col to 0.
*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int col0 = 1; // Tracks if 0th column should be zeroed

        // Step 1: Mark zeros using 1st row and 1st column
        for (int i = 0; i < n; i++) {
            if (matrix[i][0] == 0) {
                col0 = 0;
            }
            for (int j = 1; j < m; j++) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Update inner cells
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle 1st row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }

        // Step 4: Handle 1st column
        if (col0 == 0) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
