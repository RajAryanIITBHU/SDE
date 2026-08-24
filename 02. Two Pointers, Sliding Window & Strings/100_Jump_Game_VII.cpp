// Link: https://leetcode.com/problems/jump-game-vii/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (DP + Sliding Window of Reachable Count)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. dp[i] is true if index i is reachable.
2. dp[0] = true.
3. Maintain reachableCount: number of reachable indices that can jump to current index i.
4. For i from 1 to n-1:
     if i >= minJump && dp[i - minJump] -> reachableCount++
     if i > maxJump && dp[i - maxJump - 1] -> reachableCount--
     if s[i] == '0' && reachableCount > 0 -> dp[i] = true
5. Return dp[n - 1].
*/

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] != '0') return false;

        vector<bool> dp(n, false);
        dp[0] = true;

        int reachableCount = 0;

        for (int i = 1; i < n; i++) {
            // Add reachable position entering jump window
            if (i >= minJump && dp[i - minJump]) {
                reachableCount++;
            }
            // Remove reachable position leaving jump window
            if (i > maxJump && dp[i - maxJump - 1]) {
                reachableCount--;
            }

            if (s[i] == '0' && reachableCount > 0) {
                dp[i] = true;
            }
        }

        return dp[n - 1];
    }
};
