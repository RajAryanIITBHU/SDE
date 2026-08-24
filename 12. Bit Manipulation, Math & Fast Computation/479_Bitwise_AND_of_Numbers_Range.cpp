// Link: https://leetcode.com/problems/bitwise-and-of-numbers-range/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Finding Common Binary Prefix via Right Shift)
// ==========================================
// Time Complexity  : O(log(right)) = O(32) = O(1)
// Space Complexity : O(1)
/*
PSEUDOCODE:
Bitwise AND of range [left, right] equals the common binary prefix of left and right,
with trailing bits padded with 0s.
1. shiftCount = 0.
2. While left < right:
     left >>= 1
     right >>= 1
     shiftCount++
3. Return left << shiftCount.
*/

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shiftCount = 0;

        // Shift right until common binary prefix is found
        while (left < right) {
            left >>= 1;
            right >>= 1;
            shiftCount++;
        }

        return left << shiftCount;
    }
};
