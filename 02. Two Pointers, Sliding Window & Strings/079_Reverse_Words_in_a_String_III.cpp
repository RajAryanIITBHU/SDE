// Link: https://leetcode.com/problems/reverse-words-in-a-string-iii/

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Two Pointers In-Place Word Reverse)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) in-place
/*
PSEUDOCODE:
1. Initialize i = 0.
2. While i < n:
     start = i
     While i < n and s[i] != ' ' -> i++
     reverse(s.begin() + start, s.begin() + i)
     i++ // Skip the space
3. Return s.
*/

class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        int i = 0;

        while (i < n) {
            int start = i;

            // Find word boundary
            while (i < n && s[i] != ' ') {
                i++;
            }

            // Reverse current word
            reverse(s.begin() + start, s.begin() + i);

            // Move to start of next word
            i++;
        }

        return s;
    }
};
