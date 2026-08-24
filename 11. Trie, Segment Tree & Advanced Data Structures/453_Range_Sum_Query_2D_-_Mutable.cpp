// Link: https://leetcode.com/problems/range-sum-query-2d-mutable/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (2D Binary Indexed Tree / Fenwick Tree)
// ==========================================
// Time Complexity  : Constructor: O(n * m * log n * log m), update: O(log n * log m), sumRegion: O(log n * log m)
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
2D Fenwick Tree:
1. bit2D matrix of size (n + 1) x (m + 1).
2. add(r, c, delta):
     for i = r; i <= n; i += i & (-i):
         for j = c; j <= m; j += j & (-j):
             bit2D[i][j] += delta
3. query(r, c):
     sum = 0
     for i = r; i > 0; i -= i & (-i):
         for j = c; j > 0; j -= j & (-j):
             sum += bit2D[i][j]
     return sum
4. sumRegion(r1, c1, r2, c2):
     return query(r2+1, c2+1) - query(r1, c2+1) - query(r2+1, c1) + query(r1, c1)
*/

class NumMatrix {
private:
    vector<vector<int>> bit;
    vector<vector<int>> matrix;
    int n, m;

    void add(int r, int c, int delta) {
        for (int i = r; i <= n; i += i & (-i)) {
            for (int j = c; j <= m; j += j & (-j)) {
                bit[i][j] += delta;
            }
        }
    }

    int query(int r, int c) {
        int sum = 0;
        for (int i = r; i > 0; i -= i & (-i)) {
            for (int j = c; j > 0; j -= j & (-j)) {
                sum += bit[i][j];
            }
        }
        return sum;
    }

public:
    NumMatrix(vector<vector<int>>& mat) {
        n = mat.size();
        m = mat[0].size();
        matrix = mat;
        bit.assign(n + 1, vector<int>(m + 1, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                add(i + 1, j + 1, mat[i][j]);
            }
        }
    }

    void update(int row, int col, int val) {
        int delta = val - matrix[row][col];
        matrix[row][col] = val;
        add(row + 1, col + 1, delta);
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return query(row2 + 1, col2 + 1)
             - query(row1, col2 + 1)
             - query(row2 + 1, col1)
             + query(row1, col1);
    }
};
