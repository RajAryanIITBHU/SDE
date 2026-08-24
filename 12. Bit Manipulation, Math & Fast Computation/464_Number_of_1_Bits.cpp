// Link: https://leetcode.com/problems/number-of-1-bits/

#include <iostream>
#include <cstdint>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Brian Kernighan's Algorithm)
// ==========================================
// Time Complexity  : O(set_bits_count)
// Space Complexity : O(1)
/*
PSEUDOCODE:
n & (n - 1) always clears the lowest set bit in n.
1. count = 0.
2. While n != 0:
     n &= (n - 1)
     count++
3. Return count.
*/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;

        while (n != 0) {
            n &= (n - 1); // Clears the lowest set bit
            count++;
        }

        return count;
    }
};
