// Link: https://leetcode.com/problems/count-square-submatrices-with-all-ones/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (In-Place 2D DP)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
1. totalSquares = 0.
2. For i from 0 to n-1:
     For j from 0 to m-1:
         if matrix[i][j] == 1:
             if i > 0 && j > 0:
                 matrix[i][j] = 1 + min({matrix[i-1][j], matrix[i][j-1], matrix[i-1][j-1]})
             totalSquares += matrix[i][j]
3. Return totalSquares.
*/

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int totalSquares = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 1) {
                    if (i > 0 && j > 0) {
                        matrix[i][j] = 1 + min({matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]});
                    }
                    totalSquares += matrix[i][j];
                }
            }
        }

        return totalSquares;
    }
};
