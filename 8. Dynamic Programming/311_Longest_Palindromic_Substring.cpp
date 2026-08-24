// Link: https://leetcode.com/problems/longest-palindromic-substring/

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Expand Around Center)
// ==========================================
// Time Complexity  : O(n^2)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Helper expand(s, left, right):
     While left >= 0 && right < s.length() && s[left] == s[right]:
         left--, right++
     return right - left - 1 (length of palindrome)
2. start = 0, maxLen = 0.
3. For i from 0 to n-1:
     len1 = expand(s, i, i)       // Odd length palindrome
     len2 = expand(s, i, i + 1)   // Even length palindrome
     len = max(len1, len2)
     if len > maxLen:
         maxLen = len
         start = i - (len - 1) / 2
4. Return s.substr(start, maxLen).
*/

class Solution {
private:
    int expandAroundCenter(string& s, int left, int right) {
        while (left >= 0 && right < (int)s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }

public:
    string longestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        int start = 0;
        int maxLen = 0;

        for (int i = 0; i < n; i++) {
            int len1 = expandAroundCenter(s, i, i);     // Odd palindrome
            int len2 = expandAroundCenter(s, i, i + 1); // Even palindrome
            int len = max(len1, len2);

            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLen);
    }
};
