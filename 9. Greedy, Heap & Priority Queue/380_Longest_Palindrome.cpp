// Link: https://leetcode.com/problems/longest-palindrome/

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// ==========================================
// 1. OPTIMAL APPROACH (Frequency Pair Counting)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1) (at most 52 character keys)
/*
PSEUDOCODE:
1. Count character frequencies in unordered_map freq.
2. length = 0, hasOdd = false.
3. For each count in freq:
     length += (count / 2) * 2
     if count % 2 == 1:
         hasOdd = true
4. Return hasOdd ? length + 1 : length.
*/

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int len = 0;
        bool hasOdd = false;

        for (auto& p : freq) {
            len += (p.second / 2) * 2;
            if (p.second % 2 == 1) {
                hasOdd = true;
            }
        }

        return hasOdd ? len + 1 : len;
    }
};
