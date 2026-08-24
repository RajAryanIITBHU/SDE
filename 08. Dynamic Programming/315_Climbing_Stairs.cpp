// Link: https://leetcode.com/problems/climbing-stairs/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Space-Optimized DP / Fibonacci)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If n <= 2 return n.
2. prev2 = 1, prev1 = 2.
3. For i from 3 to n:
     curr = prev1 + prev2
     prev2 = prev1
     prev1 = curr
4. Return prev1.
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) return n;

        int prev2 = 1; // ways to reach step 1
        int prev1 = 2; // ways to reach step 2

        for (int i = 3; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
