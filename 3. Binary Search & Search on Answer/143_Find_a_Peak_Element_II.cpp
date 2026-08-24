// Link: https://leetcode.com/problems/find-a-peak-element-ii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Columns)
// ==========================================
// Time Complexity  : O(n * log m)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Binary search on column indices: lowCol = 0, highCol = m - 1.
2. While lowCol <= highCol:
     midCol = lowCol + (highCol - lowCol) / 2
     Find the row with the maximum element in midCol: maxRow.
     leftVal = (midCol > 0) ? mat[maxRow][midCol - 1] : -1
     rightVal = (midCol < m - 1) ? mat[maxRow][midCol + 1] : -1
     
     if mat[maxRow][midCol] > leftVal && mat[maxRow][midCol] > rightVal:
         return {maxRow, midCol} // Peak found!
     else if mat[maxRow][midCol] < rightVal:
         lowCol = midCol + 1 // Peak exists in right half
     else:
         highCol = midCol - 1 // Peak exists in left half
*/

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int lowCol = 0;
        int highCol = m - 1;

        while (lowCol <= highCol) {
            int midCol = lowCol + (highCol - lowCol) / 2;

            // Find maximum element in column midCol
            int maxRow = 0;
            for (int i = 0; i < n; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            int leftVal = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
            int rightVal = (midCol < m - 1) ? mat[maxRow][midCol + 1] : -1;

            if (mat[maxRow][midCol] > leftVal && mat[maxRow][midCol] > rightVal) {
                return {maxRow, midCol};
            } else if (mat[maxRow][midCol] < rightVal) {
                lowCol = midCol + 1; // Move right
            } else {
                highCol = midCol - 1; // Move left
            }
        }

        return {-1, -1};
    }
};
