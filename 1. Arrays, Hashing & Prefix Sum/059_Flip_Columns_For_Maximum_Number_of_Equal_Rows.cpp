// Link: https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Normalized Pattern Frequency Map)
// ==========================================
// Time Complexity  : O(n * m)
// Space Complexity : O(n * m)
/*
PSEUDOCODE:
Two rows can become identical after column flips if they are identical OR exact bitwise inverses.
1. For each row:
     Normalize the row: if row[0] == 1, flip all elements so row starts with 0.
     Convert normalized row to string pattern.
     mp[pattern]++
     ans = max(ans, mp[pattern])
2. Return ans.
*/

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        unordered_map<string, int> mp;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            string pattern = "";
            int firstBit = matrix[i][0];

            // Normalize row so that it always begins with '0'
            for (int j = 0; j < m; j++) {
                pattern += (matrix[i][j] == firstBit) ? '0' : '1';
            }

            mp[pattern]++;
            ans = max(ans, mp[pattern]);
        }

        return ans;
    }
};
