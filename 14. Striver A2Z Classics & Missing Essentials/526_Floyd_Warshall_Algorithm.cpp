// Link: https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Floyd Warshall All-Pairs Shortest Path)
// ==========================================
// Time Complexity  : O(V^3)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
1. Replace -1 with 1e8 for unreachable initial edges.
2. For k from 0 to V-1:
     For i from 0 to V-1:
         For j from 0 to V-1:
             mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j])
3. Replace 1e8 back with -1.
*/

class Solution {
public:
    void shortest_distance(vector<vector<int>>& mat) {
        int n = mat.size();
        const int INF = 1e8;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == -1) {
                    mat[i][j] = INF;
                }
                if (i == j) mat[i][j] = 0;
            }
        }

        // DP state transition over all intermediate vertices k
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] >= INF) {
                    mat[i][j] = -1;
                }
            }
        }
    }
};
