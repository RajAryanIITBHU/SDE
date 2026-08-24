// Link: https://leetcode.com/problems/remove-k-digits/

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Increasing String as Stack)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Initialize string ans = "".
2. For each digit in num:
     While !ans.empty() && ans.back() > digit && k > 0:
         ans.pop_back()
         k--
     ans.push_back(digit)
3. If k > 0: remove remaining k digits from the back of ans.
4. Remove leading zeros from ans.
5. Return ans.empty() ? "0" : ans.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";

        for (char digit : num) {
            // Remove larger preceding digits
            while (!ans.empty() && ans.back() > digit && k > 0) {
                ans.pop_back();
                k--;
            }
            ans.push_back(digit);
        }

        // If k removals still remaining, pop from the back
        while (k > 0 && !ans.empty()) {
            ans.pop_back();
            k--;
        }

        // Strip leading zeros
        int start = 0;
        while (start < (int)ans.length() && ans[start] == '0') {
            start++;
        }

        ans = ans.substr(start);

        return ans.empty() ? "0" : ans;
    }
};
