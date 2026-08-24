// Link: https://leetcode.com/problems/pascals-triangle/

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. BRUTE FORCE APPROACH (Using nCr Formula)
// ==========================================
// Time Complexity  : O(numRows^3) or O(numRows^2 * numRows)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. For row from 0 to numRows - 1:
     Create arr of size row + 1.
     For col from 0 to row:
         Calculate arr[col] = nCr(row, col).
     ans.push_back(arr)
2. Return ans.
*/

class SolutionBruteForce {
private:
    long long nCr(int n, int r) {
        long long ans = 1;
        for (int i = 0; i < r; i++) {
            ans = ans * (n - i);
            ans = ans / (i + 1);
        }
        return ans;
    }

public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> arr(i + 1);
            for (int j = 0; j <= i; j++) {
                arr[j] = nCr(i, j);
            }
            ans.push_back(arr);
        }

        return ans;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (DP - Sum of Previous Row)
// ==========================================
// Time Complexity  : O(numRows^2)
// Space Complexity : O(1) auxiliary space (excluding result)
/*
PSEUDOCODE:
1. Initialize ans.
2. Loop i from 0 to numRows - 1:
     Create arr of size (i + 1) filled with 1.
     For j from 1 to i - 1:
         arr[j] = ans[i - 1][j - 1] + ans[i - 1][j]
     ans.push_back(arr)
3. Return ans.
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; i++) {
            vector<int> arr(i + 1, 1); // 1st and last elements are always 1

            // Middle elements are sum of two elements above
            for (int j = 1; j < i; j++) {
                arr[j] = ans[i - 1][j - 1] + ans[i - 1][j];
            }

            ans.push_back(arr);
        }

        return ans;
    }
};
