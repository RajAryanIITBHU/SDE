// Link: https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Extra Matrix)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
1. Create new matrix arr of size n x n.
2. For i from 0 to n-1:
     For j from 0 to n-1:
         arr[j][n - 1 - i] = matrix[i][j]
3. Copy arr back to matrix.
*/

class SolutionBruteForce {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> arr(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                arr[j][n - 1 - i] = matrix[i][j];
            }
        }

        matrix = arr;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Transpose + Reverse Rows)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
1. Step 1 (Transpose):
     For i from 0 to n-1:
         For j from i+1 to n-1:
             swap(matrix[i][j], matrix[j][i])
2. Step 2 (Reverse each row):
     For i from 0 to n-1:
         reverse(matrix[i].begin(), matrix[i].end())
*/

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: Transpose matrix (swap elements across main diagonal)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: Reverse each row
        for (int i = 0; i < n; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
