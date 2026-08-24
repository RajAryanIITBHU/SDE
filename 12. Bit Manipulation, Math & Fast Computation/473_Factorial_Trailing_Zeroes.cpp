// Link: https://leetcode.com/problems/factorial-trailing-zeroes/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Count Factors of 5 / Legendre's Formula)
// ==========================================
// Time Complexity  : O(log5(n))
// Space Complexity : O(1)
/*
PSEUDOCODE:
Trailing zeroes are determined by factors of 10 = 2 * 5. Since factors of 2 are always abundant,
count factors of 5 in n!:
  count = n/5 + n/25 + n/125 + ...
1. zeroes = 0.
2. While n > 0:
     zeroes += n / 5
     n /= 5
3. Return zeroes.
*/

class Solution {
public:
    int trailingZeroes(int n) {
        int zeroes = 0;

        while (n > 0) {
            zeroes += n / 5;
            n /= 5;
        }

        return zeroes;
    }
};
