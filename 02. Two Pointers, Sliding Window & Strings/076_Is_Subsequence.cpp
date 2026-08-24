// Link: https://leetcode.com/problems/is-subsequence/

#include <iostream>
#include <string>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers)
// ==========================================
// Time Complexity  : O(t.length())
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize i = 0 (pointer in s), j = 0 (pointer in t).
2. While i < s.length() and j < t.length():
     if s[i] == t[j] -> i++
     j++
3. Return i == s.length().
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n = s.length();
        int m = t.length();

        int i = 0; // Pointer for string s
        int j = 0; // Pointer for string t

        while (i < n && j < m) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return i == n;
    }
};
