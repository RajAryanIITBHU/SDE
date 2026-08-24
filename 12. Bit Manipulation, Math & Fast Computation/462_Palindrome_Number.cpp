// Link: https://leetcode.com/problems/palindrome-number/

#include <iostream>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Reversing Half of the Integer)
// ==========================================
// Time Complexity  : O(log10(n))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Negative numbers and numbers ending in 0 (except 0 itself) are not palindromes.
2. reversedHalf = 0.
3. While x > reversedHalf:
     reversedHalf = reversedHalf * 10 + x % 10
     x /= 10
4. Return x == reversedHalf || x == reversedHalf / 10.
*/

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // For even number of digits: x == reversedHalf
        // For odd number of digits: x == reversedHalf / 10
        return x == reversedHalf || x == reversedHalf / 10;
    }
};
