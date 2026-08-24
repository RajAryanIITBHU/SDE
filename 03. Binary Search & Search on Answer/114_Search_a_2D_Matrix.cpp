// Link: https://leetcode.com/problems/search-a-2d-matrix/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Virtual 1D Binary Search)
// ==========================================
// Time Complexity  : O(log(n * m))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Flatten matrix conceptually: size = n * m.
2. low = 0, high = n * m - 1.
3. While low <= high:
     mid = low + (high - low) / 2
     r = mid / m
     c = mid % m
     if matrix[r][c] == target -> return true
     else if matrix[r][c] < target -> low = mid + 1
     else -> high = mid - 1
4. Return false.
*/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = n * m - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;
            int r = mid / m;
            int c = mid % m;

            if (matrix[r][c] == target) {
                return true;
            } else if (matrix[r][c] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false;
    }
};
