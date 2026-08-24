// Link: https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Row Prefix Sums + 1D Subarray Sum)
// ==========================================
// Time Complexity  : O(m^2 * n) or O(n^2 * m)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Compute prefix sums for each row of the matrix.
2. Fix two columns: col1 from 0 to m-1 and col2 from col1 to m-1.
3. For each pair (col1, col2), compress each row into a single 1D value:
     sum = row[i][col2] - (col1 > 0 ? row[i][col1 - 1] : 0)
4. Apply 1D Subarray Sum Equals Target using hash map mp.
5. Return ans.
*/

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Step 1: Compute prefix sums along each row
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < m; j++) {
                matrix[i][j] += matrix[i][j - 1];
            }
        }

        int ans = 0;

        // Step 2: Fix two columns and reduce to 1D problem
        for (int col1 = 0; col1 < m; col1++) {
            for (int col2 = col1; col2 < m; col2++) {
                unordered_map<int, int> mp; // {prefixSum, count}
                mp[0] = 1;
                int sum = 0;

                for (int i = 0; i < n; i++) {
                    // Sum of submatrix in row i from col1 to col2
                    int rowSum = matrix[i][col2] - (col1 > 0 ? matrix[i][col1 - 1] : 0);
                    sum += rowSum;

                    int rem = sum - target;
                    if (mp.find(rem) != mp.end()) {
                        ans += mp[rem];
                    }

                    mp[sum]++;
                }
            }
        }

        return ans;
    }
};
