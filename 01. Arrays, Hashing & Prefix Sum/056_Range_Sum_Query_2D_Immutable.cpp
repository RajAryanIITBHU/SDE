// Link: https://leetcode.com/problems/range-sum-query-2d-immutable/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (2D Prefix Sum Matrix)
// ==========================================
// Time Complexity  : O(1) per query, O(n * m) precomputation
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
1. Build (n+1) x (m+1) prefix sum matrix PS.
2. PS[i+1][j+1] = matrix[i][j] + PS[i][j+1] + PS[i+1][j] - PS[i][j].
3. In sumRegion(r1, c1, r2, c2):
     return PS[r2+1][c2+1] - PS[r1][c2+1] - PS[r2+1][c1] + PS[r1][c1].
*/

class NumMatrix {
private:
    vector<vector<int>> PS;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        PS.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                PS[i + 1][j + 1] = matrix[i][j] 
                                 + PS[i][j + 1] 
                                 + PS[i + 1][j] 
                                 - PS[i][j];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return PS[row2 + 1][col2 + 1] 
             - PS[row1][col2 + 1] 
             - PS[row2 + 1][col1] 
             + PS[row1][col1];
    }
};
