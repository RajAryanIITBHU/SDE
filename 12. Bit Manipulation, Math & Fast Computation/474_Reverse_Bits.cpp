// Link: https://leetcode.com/problems/reverse-bits/

#include <iostream>
#include <cstdint>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Bitwise Extraction & Insertion)
// ==========================================
// Time Complexity  : O(1) (32 operations)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. ans = 0.
2. For i from 0 to 31:
     ans = (ans << 1) | (n & 1)
     n >>= 1
3. Return ans.
*/

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;

        for (int i = 0; i < 32; i++) {
            ans = (ans << 1) | (n & 1);
            n >>= 1;
        }

        return ans;
    }
};
