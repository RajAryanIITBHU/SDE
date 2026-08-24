// Link: https://leetcode.com/problems/powx-n/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Binary Exponentiation)
// ==========================================
// Time Complexity  : O(log n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. exp = n (cast to long long to prevent INT_MIN overflow).
2. If exp < 0:
     x = 1.0 / x
     exp = -exp
3. ans = 1.0.
4. While exp > 0:
     if exp & 1: ans *= x
     x *= x
     exp >>= 1
5. Return ans.
*/

class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;
        if (exp < 0) {
            x = 1.0 / x;
            exp = -exp;
        }

        double ans = 1.0;

        while (exp > 0) {
            if (exp & 1) {
                ans *= x;
            }
            x *= x;
            exp >>= 1;
        }

        return ans;
    }
};
