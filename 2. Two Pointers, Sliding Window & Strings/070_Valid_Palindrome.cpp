// Link: https://leetcode.com/problems/valid-palindrome/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// ==========================================
// 1. BETTER APPROACH (Filtered String + Reverse)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(n)
/*
PSEUDOCODE:
1. Filter string to only lowercase alphanumeric characters: filtered.
2. Check if filtered == reverse(filtered).
*/

class SolutionBetter {
public:
    bool isPalindrome(string s) {
        string filtered = "";
        for (char c : s) {
            if (isalnum(c)) {
                filtered += tolower(c);
            }
        }

        int left = 0;
        int right = (int)filtered.length() - 1;

        while (left < right) {
            if (filtered[left] != filtered[right]) return false;
            left++;
            right--;
        }

        return true;
    }
};

// ==========================================
// 2. OPTIMAL APPROACH (Two Pointers In-Place)
// ==========================================
// Time Complexity  : O(n)
// Space Complexity : O(1)
/*
PSEUDOCODE:
1. Initialize left = 0, right = n - 1.
2. While left < right:
     While left < right and !isalnum(s[left]) -> left++
     While left < right and !isalnum(s[right]) -> right--
     if tolower(s[left]) != tolower(s[right]) -> return false
     left++, right--
3. Return true.
*/

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = (int)s.length() - 1;

        while (left < right) {
            // Skip non-alphanumeric characters
            while (left < right && !isalnum(s[left])) left++;
            while (left < right && !isalnum(s[right])) right--;

            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }
};
