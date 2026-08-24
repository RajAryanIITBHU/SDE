// Link: https://leetcode.com/problems/decode-ways/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (1D Space-Optimized DP)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. If s[0] == '0' return 0.
2. prev2 = 1, prev1 = 1.
3. For i from 2 to n:
     curr = 0
     oneDigit = s[i-1] - '0'
     twoDigits = stoi(s.substr(i-2, 2))
     if oneDigit >= 1 && oneDigit <= 9: curr += prev1
     if twoDigits >= 10 && twoDigits <= 26: curr += prev2
     prev2 = prev1
     prev1 = curr
4. Return prev1.
*/

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        if (n == 0 || s[0] == '0') return 0;

        int prev2 = 1; // dp[i-2]
        int prev1 = 1; // dp[i-1]

        for (int i = 1; i < n; i++) {
            int curr = 0;
            int oneDigit = s[i] - '0';
            int twoDigits = (s[i - 1] - '0') * 10 + oneDigit;

            // Single character decode (1..9)
            if (oneDigit >= 1 && oneDigit <= 9) {
                curr += prev1;
            }

            // Two characters decode (10..26)
            if (twoDigits >= 10 && twoDigits <= 26) {
                curr += prev2;
            }

            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
};
