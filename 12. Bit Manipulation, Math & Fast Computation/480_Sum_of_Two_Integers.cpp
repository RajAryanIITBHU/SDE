// Link: https://leetcode.com/problems/sum-of-two-integers/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bitwise Addition with XOR and Carry Shift)
// ==========================================
// Time Complexity  : O(32) = O(1)
// Space Complexity : O(1)
/*
PSEUDOCODE:
Half adder logic:
  sum = a ^ b (addition without carry)
  carry = (a & b) << 1
Repeat until carry == 0.
1. While b != 0:
     carry = (unsigned int)(a & b) << 1
     a = a ^ b
     b = carry
2. Return a.
*/

class Solution {
public:
    int getSum(int a, int b) {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }

        return a;
    }
};
