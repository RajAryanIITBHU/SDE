// Link: https://leetcode.com/problems/divide-two-integers/

#include <iostream>
#include <climits>
#include <cmath>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bit Shifting Exponential Subtraction)
// ==========================================
// Time Complexity  : O(log^2(dividend))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Handle edge case: dividend == INT_MIN && divisor == -1 return INT_MAX.
2. Determine sign = (dividend < 0) ^ (divisor < 0) ? -1 : 1.
3. Convert to positive long long: a = abs((long long)dividend), b = abs((long long)divisor).
4. ans = 0.
5. While a >= b:
     temp = b, count = 1
     While a >= (temp << 1):
         temp <<= 1
         count <<= 1
     a -= temp
     ans += count
6. Return sign < 0 ? -ans : ans.
*/

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX; // Overflow case
        }

        bool isNegative = (dividend < 0) ^ (divisor < 0);

        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long ans = 0;

        while (a >= b) {
            long long temp = b;
            long long multiple = 1;

            while (a >= (temp << 1)) {
                temp <<= 1;
                multiple <<= 1;
            }

            a -= temp;
            ans += multiple;
        }

        return isNegative ? -ans : ans;
    }
};
