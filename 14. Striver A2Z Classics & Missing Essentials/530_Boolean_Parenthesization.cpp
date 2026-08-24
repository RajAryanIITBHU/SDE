// Link: https://www.geeksforgeeks.org/problems/boolean-parenthesization5610/1

#include <iostream>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Interval MCM Matrix DP / Memoization)
// ==========================================
// Time Complexity  : O(n^3)
// Space Complexity : O(n^2)
/*
PSEUDOCODE:
dp[i][j][isTrue] = number of ways to parenthesize sub-expression s[i..j] to evaluate to isTrue.
1. Base cases:
     if i > j return 0
     if i == j:
         if isTrue: return s[i] == 'T'
         else: return s[i] == 'F'
2. Split at every operator index k from i+1 to j-1 with step 2:
     Evaluate combinations of (lT, lF) and (rT, rF) for operator '&', '|', '^'.
3. Return dp[0][n-1][1] modulo 1003.
*/

class Solution {
private:
    int memo[201][201][2];
    const int MOD = 1003;

    int solve(int i, int j, int isTrue, const string& s) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue) return s[i] == 'T' ? 1 : 0;
            else return s[i] == 'F' ? 1 : 0;
        }

        if (memo[i][j][isTrue] != -1) {
            return memo[i][j][isTrue];
        }

        int ways = 0;

        for (int k = i + 1; k <= j - 1; k += 2) {
            int lT = solve(i, k - 1, 1, s);
            int lF = solve(i, k - 1, 0, s);
            int rT = solve(k + 1, j, 1, s);
            int rF = solve(k + 1, j, 0, s);

            char op = s[k];

            if (op == '&') {
                if (isTrue) {
                    ways = (ways + (lT * rT) % MOD) % MOD;
                } else {
                    ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD + (lF * rF) % MOD) % MOD;
                }
            } else if (op == '|') {
                if (isTrue) {
                    ways = (ways + (lT * rT) % MOD + (lT * rF) % MOD + (lF * rT) % MOD) % MOD;
                } else {
                    ways = (ways + (lF * rF) % MOD) % MOD;
                }
            } else if (op == '^') {
                if (isTrue) {
                    ways = (ways + (lT * rF) % MOD + (lF * rT) % MOD) % MOD;
                } else {
                    ways = (ways + (lT * rT) % MOD + (lF * rF) % MOD) % MOD;
                }
            }
        }

        return memo[i][j][isTrue] = ways;
    }

public:
    int countWays(int n, string s) {
        memset(memo, -1, sizeof(memo));
        return solve(0, n - 1, 1, s);
    }
};
