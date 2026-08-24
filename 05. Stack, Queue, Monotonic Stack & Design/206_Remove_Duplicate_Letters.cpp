// Link: https://leetcode.com/problems/remove-duplicate-letters/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Monotonic Increasing Stack + Frequency Tracking)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (26 characters)
/*
PSEUDOCODE:
1. Record last seen index for each character in s: lastSeen.
2. Maintain inStack boolean array of size 26, and ans string as stack.
3. For i from 0 to n-1:
     char c = s[i]
     if inStack[c - 'a'] -> continue
     While !ans.empty() && ans.back() > c && lastSeen[ans.back() - 'a'] > i:
         inStack[ans.back() - 'a'] = false
         ans.pop_back()
     ans.push_back(c)
     inStack[c - 'a'] = true
4. Return ans.
*/

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> lastSeen(26, 0);
        vector<bool> inStack(26, false);

        for (int i = 0; i < n; i++) {
            lastSeen[s[i] - 'a'] = i;
        }

        string ans = "";

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (inStack[c - 'a']) continue;

            // Greedily remove larger characters if they appear again later
            while (!ans.empty() && ans.back() > c && lastSeen[ans.back() - 'a'] > i) {
                inStack[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans.push_back(c);
            inStack[c - 'a'] = true;
        }

        return ans;
    }
};
