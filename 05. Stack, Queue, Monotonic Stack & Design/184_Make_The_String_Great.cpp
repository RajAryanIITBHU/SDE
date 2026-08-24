// Link: https://leetcode.com/problems/make-the-string-great/

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (String as Stack with ASCII Diff 32)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n) for result string
/*
PSEUDOCODE:
1. Initialize string ans = "".
2. For each char c in s:
     if !ans.empty() && abs(ans.back() - c) == 32:
         ans.pop_back() // Same letter with different cases
     else:
         ans.push_back(c)
3. Return ans.
*/

class Solution {
public:
    string makeGood(string s) {
        string ans = "";

        for (char c : s) {
            // Check if last character and current character form a bad pair (diff in ASCII is 32)
            if (!ans.empty() && abs(ans.back() - c) == 32) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }

        return ans;
    }
};
