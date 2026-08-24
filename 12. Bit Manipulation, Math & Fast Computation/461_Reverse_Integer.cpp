// Link: https://leetcode.com/problems/reverse-integer/

#include <iostream>
#include <climits>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Digit Extraction with Overflow Detection)
// ==========================================
// Time Complexity  : O(log10(n))
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. ans = 0.
2. While x != 0:
     digit = x % 10
     x /= 10
     if ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7) return 0
     if ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8) return 0
     ans = ans * 10 + digit
3. Return ans.
*/

class Solution {
public:
    int reverse(int x) {
        int ans = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Overflow checks for 32-bit signed integer
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && digit > 7)) {
                return 0;
            }
            if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && digit < -8)) {
                return 0;
            }

            ans = ans * 10 + digit;
        }

        return ans;
    }
};
