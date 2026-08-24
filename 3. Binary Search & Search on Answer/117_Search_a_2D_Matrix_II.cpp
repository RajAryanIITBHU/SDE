// Link: https://leetcode.com/problems/search-a-2d-matrix-ii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Staircase Search from Top-Right)
// ==========================================
// Time Complexity  : O(n + m)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Start at top-right corner: r = 0, c = m - 1.
2. While r < n and c >= 0:
     if matrix[r][c] == target -> return true
     else if matrix[r][c] > target -> c-- (eliminate column)
     else -> r++ (eliminate row)
3. Return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int r = 0;
        int c = m - 1; // Start at top-right corner

        while (r < n && c >= 0) {
            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] > target) {
                c--; // Move left
            } else {
                r++; // Move down
            }
        }

        return false;
    }
};
