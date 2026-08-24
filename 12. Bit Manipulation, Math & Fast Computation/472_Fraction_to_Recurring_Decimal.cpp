// Link: https://leetcode.com/problems/fraction-to-recurring-decimal/

#include <iostream>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Long Division with Remainder Hash Map)
// ==========================================
// Time Complexity  : O(denominator)
// Space Complexity : O(denominator)
/*
PSEUDOCODE:
1. If numerator == 0 return "0".
2. Handle sign.
3. n = abs((long long)numerator), d = abs((long long)denominator).
4. Integer part: ans += to_string(n / d).
5. rem = n % d.
6. If rem == 0 return ans.
7. ans += ".".
8. Maintain seenReminders map: rem -> indexInAns.
9. While rem != 0:
     if rem in seenReminders:
         insert '(' at seenReminders[rem], append ')'
         break
     seenReminders[rem] = ans.length()
     rem *= 10
     ans += to_string(rem / d)
     rem %= d
10. Return ans.
*/

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";

        string ans = "";

        // Sign
        if ((numerator < 0) ^ (denominator < 0)) {
            ans += "-";
        }

        long long n = abs((long long)numerator);
        long long d = abs((long long)denominator);

        // Integer part
        ans += to_string(n / d);
        long long rem = n % d;

        if (rem == 0) {
            return ans;
        }

        ans += ".";
        unordered_map<long long, int> seenRemainders; // rem -> string index

        while (rem != 0) {
            if (seenRemainders.find(rem) != seenRemainders.end()) {
                ans.insert(seenRemainders[rem], "(");
                ans += ")";
                break;
            }

            seenRemainders[rem] = ans.length();
            rem *= 10;
            ans += to_string(rem / d);
            rem %= d;
        }

        return ans;
    }
};
