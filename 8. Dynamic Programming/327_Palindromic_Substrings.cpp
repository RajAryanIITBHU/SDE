// Link: https://leetcode.com/problems/palindromic-substrings/

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
1. Helper countPalindromes(s, left, right):
     count = 0
     While left >= 0 && right < s.length() && s[left] == s[right]:
         count++, left--, right++
     return count
2. total = 0.
3. For i from 0 to n-1:
     total += countPalindromes(s, i, i)     // Odd length
     total += countPalindromes(s, i, i + 1) // Even length
4. Return total.
*/

class Solution {
private:
    int countPalindromes(string& s, int left, int right) {
        int count = 0;
        while (left >= 0 && right < (int)s.length() && s[left] == s[right]) {
            count++;
            left--;
            right++;
        }
        return count;
    }

public:
    int countSubstrings(string s) {
        int total = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            total += countPalindromes(s, i, i);     // Center at i
            total += countPalindromes(s, i, i + 1); // Center between i and i+1
        }

        return total;
    }
};
