// Link: https://leetcode.com/problems/restore-ip-addresses/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Backtracking with 4-Segment Validation)
// ==========================================
// Time Complexity  : O(3^4) = O(81) = O(1)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper backtrack(idx, segments, currentIP, s, ans):
     if segments == 4 && idx == s.length():
         ans.push_back(currentIP)
         return
     if segments == 4 || idx == s.length():
         return
     For len from 1 to 3:
         if idx + len > s.length() break
         part = s.substr(idx, len)
         val = stoi(part)
         // Check valid segment: no leading zeroes if length > 1 and val <= 255
         if (part[0] == '0' && len > 1) || val > 255 break
         prefix = (segments == 0) ? "" : "."
         backtrack(idx + len, segments + 1, currentIP + prefix + part, s, ans)
2. backtrack(0, 0, "", s, ans).
3. Return ans.
*/

class Solution {
private:
    void backtrack(int idx, int segments, string currentIP, const string& s, vector<string>& ans) {
        if (segments == 4 && idx == (int)s.length()) {
            ans.push_back(currentIP);
            return;
        }

        if (segments == 4 || idx == (int)s.length()) {
            return;
        }

        for (int len = 1; len <= 3; len++) {
            if (idx + len > (int)s.length()) break;

            string part = s.substr(idx, len);
            int val = stoi(part);

            // Valid IP segment conditions: 0..255 and no leading zeros
            if ((part[0] == '0' && len > 1) || val > 255) {
                break;
            }

            string nextIP = currentIP + (segments == 0 ? "" : ".") + part;
            backtrack(idx + len, segments + 1, nextIP, s, ans);
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        if (s.length() < 4 || s.length() > 12) return {};

        vector<string> ans;
        backtrack(0, 0, "", s, ans);
        return ans;
    }
};
