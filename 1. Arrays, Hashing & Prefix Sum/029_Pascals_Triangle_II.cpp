// Link: https://leetcode.com/problems/pascals-triangle-ii/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Generate Full Triangle)
// ==========================================
// Time Complexity  : O(rowIndex^2)
// Space Complexity : O(rowIndex^2)
/*
PSEUDOCODE:
1. Generate all rows of Pascal's triangle up to rowIndex.
2. Return the last row.
*/

class SolutionBruteForce {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;

        for (int i = 0; i <= rowIndex; i++) {
            vector<int> arr(i + 1, 1);
            for (int j = 1; j < i; j++) {
                arr[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(arr);
        }

        return triangle[rowIndex];
    }
};

// ==========================================
// 2. BETTER APPROACH (1D Array In-place Update)
// ==========================================
// Time Complexity  : O(rowIndex^2)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize ans of size rowIndex + 1 filled with 0, and ans[0] = 1.
2. For i from 1 to rowIndex:
     For j from i down to 1:
         ans[j] = ans[j] + ans[j - 1]
3. Return ans.
*/

class SolutionBetter {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 0);
        ans[0] = 1;

        for (int i = 1; i <= rowIndex; i++) {
            // Traverse backwards to update in-place without overwriting needed values
            for (int j = i; j >= 1; j--) {
                ans[j] = ans[j] + ans[j - 1];
            }
        }

        return ans;
    }
};

// ==========================================
// 3. OPTIMAL APPROACH (Direct Formula - O(N) Time)
// ==========================================
// Time Complexity  : O(rowIndex)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize ans of size rowIndex + 1 with ans[0] = 1.
2. For i from 1 to rowIndex:
     ans[i] = (ans[i - 1] * (rowIndex - i + 1)) / i
3. Return ans.
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex + 1, 1);
        long long val = 1;

        for (int i = 1; i <= rowIndex; i++) {
            val = val * (rowIndex - i + 1) / i;
            ans[i] = val;
        }

        return ans;
    }
};
