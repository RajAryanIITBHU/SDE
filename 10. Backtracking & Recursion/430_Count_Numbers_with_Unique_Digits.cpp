// Link: https://leetcode.com/problems/count-numbers-with-unique-digits/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Combinatorics / Math)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If n == 0 return 1.
2. ans = 10, uniqueDigits = 9, availableDigits = 9.
3. For i from 2 to min(n, 10):
     uniqueDigits *= availableDigits
     ans += uniqueDigits
     availableDigits--
4. Return ans.
*/

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1;

        int ans = 10;
        int uniqueDigits = 9;
        int availableDigits = 9;

        for (int i = 2; i <= n && availableDigits > 0; i++) {
            uniqueDigits *= availableDigits;
            ans += uniqueDigits;
            availableDigits--;
        }

        return ans;
    }
};
