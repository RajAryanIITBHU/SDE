// Link: https://leetcode.com/problems/n-th-tribonacci-number/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Space-Optimized Iterative DP)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If n == 0 return 0.
2. If n == 1 || n == 2 return 1.
3. t0 = 0, t1 = 1, t2 = 1.
4. For i from 3 to n:
     t3 = t0 + t1 + t2
     t0 = t1
     t1 = t2
     t2 = t3
5. Return t2.
*/

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n <= 2) return 1;

        int t0 = 0, t1 = 1, t2 = 1;

        for (int i = 3; i <= n; i++) {
            int t3 = t0 + t1 + t2;
            t0 = t1;
            t1 = t2;
            t2 = t3;
        }

        return t2;
    }
};
