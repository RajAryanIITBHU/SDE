// Link: https://leetcode.com/problems/fibonacci-number/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Space-Optimized Iterative DP)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If n <= 1 return n.
2. prev2 = 0, prev1 = 1.
3. For i from 2 to n:
     curr = prev1 + prev2
     prev2 = prev1
     prev1 = curr
4. Return prev1.
*/

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int prev2 = 0;
        int prev1 = 1;

        for (int i = 2; i <= n; i++) {
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
