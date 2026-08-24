// Link: https://www.geeksforgeeks.org/problems/the-celebrity-problem/1

#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two-Pointer Elimination)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. i = 0, j = n - 1.
2. While i < j:
     if mat[i][j] == 1: i++ (i knows j, so i cannot be a celebrity)
     else: j-- (i doesn't know j, so j cannot be a celebrity)
3. Candidate is i.
4. Verify candidate i:
     Row i must be all 0s (candidate knows nobody).
     Col i must be all 1s except at i (everyone knows candidate).
5. Return candidate if valid, else -1.
*/

class Solution {
public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        int i = 0;
        int j = n - 1;

        while (i < j) {
            if (mat[i][j] == 1) {
                i++; // i knows j, i cannot be celebrity
            } else {
                j--; // i does not know j, j cannot be celebrity
            }
        }

        int candidate = i;

        // Verify candidate
        for (int k = 0; k < n; k++) {
            if (k != candidate) {
                if (mat[candidate][k] == 1 || mat[k][candidate] == 0) {
                    return -1;
                }
            }
        }

        return candidate;
    }
};
