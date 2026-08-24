// Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Search on Value Range)
// ==========================================
// Time Complexity  : O(n * log(max_val - min_val))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper countLessEqual(mid): counts elements in matrix <= mid in O(n) time using staircase scan.
     count = 0, row = n - 1, col = 0
     While row >= 0 and col < n:
         if matrix[row][col] <= mid:
             count += (row + 1)
             col++
         else:
             row--
     return count
2. low = matrix[0][0], high = matrix[n-1][n-1], ans = low.
3. While low <= high:
     mid = low + (high - low) / 2
     if countLessEqual(mid) >= k:
         ans = mid
         high = mid - 1 // Try smaller value
     else:
         low = mid + 1
4. Return ans.
*/

class Solution {
private:
    int countLessEqual(vector<vector<int>>& matrix, int mid, int n) {
        int count = 0;
        int row = n - 1;
        int col = 0;

        // Staircase traversal from bottom-left
        while (row >= 0 && col < n) {
            if (matrix[row][col] <= mid) {
                count += (row + 1); // All elements above this row in column 'col' are also <= mid
                col++;
            } else {
                row--;
            }
        }

        return count;
    }

public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n - 1][n - 1];
        int ans = low;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (countLessEqual(matrix, mid, n) >= k) {
                ans = mid;
                high = mid - 1; // Try smaller candidate
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
