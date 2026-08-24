// Link: https://leetcode.com/problems/power-of-two/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bitwise Lowest Bit Clearing)
// ==========================================
// Time Complexity  : O(1)
// Space Complexity : O(1)
/*
PSEUDOCODE:
A positive number is a power of two if and only if it has exactly one set bit.
Clearing that bit using n & (n - 1) leaves 0.
1. Return n > 0 && (n & (n - 1)) == 0.
*/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1LL)) == 0;
    }
};
