// Link: https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (2D Dynamic Programming)
// ==========================================
// Time Complexity  : O(d * n^2)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. If n < d return -1.
2. Initialize dp array of size n with max difficulty from i to n-1 (for day 1).
3. For day from 2 to d:
     vector<int> nextDP(n, INT_MAX)
     For i from 0 to n - day:
         maxDiff = 0
         For j from i to n - day:
             maxDiff = max(maxDiff, jobDifficulty[j])
             if dp[j + 1] != INT_MAX:
                 nextDP[i] = min(nextDP[i], maxDiff + dp[j + 1])
     dp = nextDP
4. Return dp[0].
*/

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        if (n < d) return -1;

        vector<int> dp(n, 0);

        // Base case: day 1 (last remaining day doing all remaining jobs)
        int maxDiff = 0;
        for (int i = n - 1; i >= 0; i--) {
            maxDiff = max(maxDiff, jobDifficulty[i]);
            dp[i] = maxDiff;
        }

        // Fill for days 2 to d
        for (int day = 2; day <= d; day++) {
            vector<int> nextDP(n, INT_MAX);

            for (int i = 0; i <= n - day; i++) {
                int currentMax = 0;

                for (int j = i; j <= n - day; j++) {
                    currentMax = max(currentMax, jobDifficulty[j]);
                    if (dp[j + 1] != INT_MAX) {
                        nextDP[i] = min(nextDP[i], currentMax + dp[j + 1]);
                    }
                }
            }

            dp = nextDP;
        }

        return dp[0];
    }
};
