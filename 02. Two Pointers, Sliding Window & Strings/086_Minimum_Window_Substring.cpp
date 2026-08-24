// Link: https://leetcode.com/problems/minimum-window-substring/

#include <iostream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Sliding Window + Frequency Tracking)
// ==========================================
// Time Complexity  : O(m + n), where m = s.length(), n = t.length()
// Space Complexity : O(1) (fixed 128-size ASCII array)
/*
PSEUDOCODE:
1. If s.length() < t.length() return "".
2. Create targetFreq array of size 128 with frequencies of chars in t.
3. required = count of unique characters in t that still need to be satisfied.
4. Initialize left = 0, minLen = INT_MAX, startIdx = 0.
5. For right from 0 to s.length() - 1:
     if s[right] in t and targetFreq[s[right]] > 0 -> required--
     targetFreq[s[right]]--
     
     While required == 0 (valid window):
         if right - left + 1 < minLen:
             minLen = right - left + 1
             startIdx = left
         targetFreq[s[left]]++
         if targetFreq[s[left]] > 0 -> required++
         left++
6. Return minLen == INT_MAX ? "" : s.substr(startIdx, minLen).
*/

class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.length();
        int n = t.length();

        if (m < n) return "";

        vector<int> targetFreq(128, 0);
        for (char c : t) {
            targetFreq[c]++;
        }

        int required = n; // Total characters needed to be matched
        int left = 0;
        int minLen = INT_MAX;
        int startIdx = 0;

        for (int right = 0; right < m; right++) {
            // If current char is needed, decrement required
            if (targetFreq[s[right]] > 0) {
                required--;
            }
            targetFreq[s[right]]--;

            // When all characters are matched, shrink window from left
            while (required == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    startIdx = left;
                }

                targetFreq[s[left]]++;
                if (targetFreq[s[left]] > 0) {
                    required++;
                }
                left++;
            }
        }

        return (minLen == INT_MAX) ? "" : s.substr(startIdx, minLen);
    }
};
